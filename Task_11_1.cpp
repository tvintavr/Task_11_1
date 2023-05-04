#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

std::string encrypt_caesar(std::string text, int key) {
    int textLength=text.length();
    int i;
    int j;
    if (key > 25 || key < 25) {
        key=key%26;
    }
    for (i=0;i<textLength;i++) {
        if (text[i]>=65 && text[i]<=90) {
            if (text[i]+key>90) {
                text[i]=text[i]-26+key;
            } else if (text[i]+key<65) {
                text[i]=text[i]+26+key;
            } else {
                text[i]=text[i]+key;
            }
        } else if (text[i]>=97 && text[i]<=122) {
            if (text[i]+key>122) {
                text[i]=text[i]-26+key;
            } else if (text[i]+key<97) {
                text[i]=text[i]+26+key;
            } else {
                text[i]=text[i]+key;
            }
        } 
    }
    return text;
}

std::string decrypt_caesar(std::string text, int key) {
    key=-key;
    return encrypt_caesar(text, key);
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */

    std::string text;
    int key;

    std::cout<<"\nEnter text: ";
    std::getline(std::cin, text);
    std::cout<<"\nEnter key: ";
    std::cin>>key;
    if (std::cin.fail() || std::cin.peek()!='\n') {
        std::cout<<"Input error\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
        std::cout<<"\nCrypted text: \n";
        text=encrypt_caesar(text,key);
        std::cout<<text;
        std::cout<<"\n";
        std::cout<<"\nDecrypted text: \n";
        std::cout<<decrypt_caesar(text,key);
        std::cout<<"\n";
    }
    

    

}
#include <iostream>
#include <string>

int main() {
    std::string str[3];

    for(int i = 0; i < 3; ++i) {
        std::cin >> str[i];
    }

    for(int i = 0; i < 3; ++i) {
        std::cout << str[i][i];
    }

    std::cout << "\n";
}
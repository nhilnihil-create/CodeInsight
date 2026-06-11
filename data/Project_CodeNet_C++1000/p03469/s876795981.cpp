#include <iostream>

int main(int argc, char **argv){

    std::string S;
    std::cin >> S;

    S.at(3) = '8';
    std::cout << S << std::endl;
}

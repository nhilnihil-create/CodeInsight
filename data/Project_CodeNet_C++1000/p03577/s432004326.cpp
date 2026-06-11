#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    std::cout << s.substr(0, s.size() - 8) << std::endl;

    return 0;
}
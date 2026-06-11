#include <iostream>
#include <string>

int main () {
  std::string str;
  std::cin >> str;
  str[3] = '8';
  std::cout << str << std::endl;
}
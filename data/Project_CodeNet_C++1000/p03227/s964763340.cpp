#include <iostream>
#include <string>
#include <algorithm>


int main() {
  
  std::string inputString;
  std::cin >> inputString;
  
  if (inputString.length() == 2) {
    std::cout << inputString << std::endl;
  } else {
    std::reverse(begin(inputString), end(inputString));
    std::cout << inputString << std::endl;
  }
  
}
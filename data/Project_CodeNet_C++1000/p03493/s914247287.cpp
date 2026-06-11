#include <iostream>
#include <string>
 
int main() {
  std::string boxes;
  std::cin >> boxes;
  int numOfBalls = 0;
  for (size_t i = 0U; i < boxes.length(); ++i) {
    if (boxes.at(i) == '1') {
      numOfBalls++;
    }
  }
  std::cout << numOfBalls;
}
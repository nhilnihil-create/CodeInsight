#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;
  if (A + B == 15) {
    std::cout << "+" << std::endl;
  } else if (A * B == 15) {
    std::cout << "*" << std::endl;
  } else {
    std::cout << "x" << std::endl;
  }
  return EXIT_SUCCESS;
}

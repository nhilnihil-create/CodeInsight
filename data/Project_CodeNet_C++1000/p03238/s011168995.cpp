#include <iostream>

int main() {
  int N;
  std::cin >> N;
  if (N == 1) std::cout << "Hello World";
  else if (N == 2) {
    int A, B;
    std::cin >> A >> B;
    std::cout << A + B;
  }
}
#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  const int m = a * b;
  if( m % 2 ) {
    std::cout << "Odd" << std::endl;
  } else {
    std::cout << "Even" << std::endl;
  }
}
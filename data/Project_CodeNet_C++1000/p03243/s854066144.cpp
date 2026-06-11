#include <iostream>
int main() {
  int n;
  std::cin >> n;
  std::cout << ((n - 1) / 111 + 1) * 111;
}
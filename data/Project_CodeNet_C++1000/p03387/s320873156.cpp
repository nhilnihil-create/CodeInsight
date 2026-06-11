#include <iostream>
#include <algorithm>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  int max = std::max({a, b, c});
  int sum = a + b + c;
  if ((max * 3 - sum) % 2 == 0) {
    std::cout << (max * 3 - sum) / 2 << "\n";
  } else {
    std::cout << (max * 3 - sum + 3) / 2 << "\n";
  }
  return 0;
}
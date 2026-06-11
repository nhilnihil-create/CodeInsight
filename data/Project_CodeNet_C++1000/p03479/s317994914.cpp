#include <iostream>

int main() {
  long long x, y;
  std::cin >> x >> y;
  long long cnt = 0;
  while (x <= y) {
    x *= 2;
    cnt++;
  }
  std::cout << cnt << "\n";
  return 0;
}
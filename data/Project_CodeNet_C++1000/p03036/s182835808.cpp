#include<iostream>
#include<cstdint>

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int r, D, x; std::cin >> r >> D >> x;
  for(int i = 0; i < 10; ++i) {
    x = r*x - D;
    std::cout << x << "\n";
  }
  return 0;
}
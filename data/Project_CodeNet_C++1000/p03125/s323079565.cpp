#include <iostream>

void solve(int b, int a) {
  if (b % a == 0)
    std::cout << a + b;
  else
    std::cout << b - a;
}

int read() {
  int t;
  std::cin >> t;
  return t;
}

int main() { solve(read(), read()); }
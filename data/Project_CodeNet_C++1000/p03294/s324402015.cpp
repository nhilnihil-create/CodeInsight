#include <iostream>

int main() {
  int n; std::cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    int a; std::cin >> a;
    s += a - 1;
  }
  std::cout << s << std::endl;
  return 0;
}

#include <iostream>
int main() {
  int n, k;
  std::cin >> n >> k;
  if (n >= 2*k-1) std::cout << "YES\n";
  else std::cout << "NO\n";
}
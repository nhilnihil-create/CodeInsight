#include <iostream>
int i{9}, c, s;
int main() {
  while (i--) std::cin >> c, s += (i % 4 ? c : -2 * c);
  std::cout << (s ? "No\n" : "Yes\n");
}

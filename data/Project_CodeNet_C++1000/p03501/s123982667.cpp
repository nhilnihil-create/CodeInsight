#include <iostream>

int main () {
  int n, a, b;
  std::cin >> n >> a >> b;
  a = a * n;
  int ans = a;
  if(a > b) ans = b;
  std::cout << ans << std::endl;
}
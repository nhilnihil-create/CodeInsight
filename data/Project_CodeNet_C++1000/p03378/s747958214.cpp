#include <iostream>
int main() {
  int n,m,x;
  std::cin >> n >> m >> x;
  int p = 0, q = 0;
  for (int i = 0; i < m; i++) {
    int a;
    std::cin >> a;
    if (a < x) p++;
    else q++;
  }
  std::cout << std::min(p,q) << std::endl;
  return 0;
}
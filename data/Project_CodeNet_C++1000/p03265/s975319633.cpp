#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  int x3 = x2 - (y2 - y1);
  int y3 = y2 + (x2 - x1);
  int x4 = x3 - (y3 - y2);
  int y4 = y3 + (x3 - x2) ;

  std::cout << x3 << " " << y3  << " " << x4 << " " << y4 << std::endl;

  return 0;
}

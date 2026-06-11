#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, y;
  std::cin >> n >> y;

  int a = 0, b = 0, c = 0;
  bool ok = false;
  rep(i, 2001) {
    rep(j, 2001) {
      if (i + j > n) {
        continue;
      }
      if (i * 10000 + j * 5000 + (n - i - j) * 1000 == y) {
        ok = true;
        a = i;
        b = j;
        c = n - i - j;
      }
    }
  }

  if (ok) {
    std::cout << a << " " << b << " " << c << std::endl;
  } else {
    std::cout << -1 << " " << -1 << " " << -1 << std::endl;
  }
  return 0;
}

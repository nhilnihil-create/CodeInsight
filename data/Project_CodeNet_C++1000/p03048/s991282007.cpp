#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int r, g, b, n;
  std::cin >> r >> g >> b >> n;

  int num = 0;
  rep(i, n / r + 1) {
    rep(j, n / g + 1) {
      int t = r * i + g * j;
      if ((n - t) % b == 0 && t <= n) {
        num++;
      }
    }
  }
  std::cout << num << std::endl;
}

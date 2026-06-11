#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int c[3][3];
  rep(i, 3) {
    rep(j, 3) { std::cin >> c[i][j]; }
  }

  bool ok = false;
  if (c[0][0] - c[0][1] == c[1][0] - c[1][1] &&
      c[1][0] - c[1][1] == c[2][0] - c[2][1] &&
      c[0][1] - c[0][2] == c[1][1] - c[1][2] &&
      c[1][1] - c[1][2] == c[2][1] - c[2][2]) {
    ok = true;
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;

  return 0;
}

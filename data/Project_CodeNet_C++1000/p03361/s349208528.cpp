#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<string> s(h);
  rep(i, h) std::cin >> s[i];

  bool ok = true;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') {
        int dx1 = i - 1;
        int dx2 = i + 1;
        int dy1 = j - 1;
        int dy2 = j + 1;

        if ((dx1 >= 0 && dx2 < h && s[dx1][j] != '#' && s[dx2][j] != '#') &&
            (dy1 >= 0 && dy2 < w && s[i][dy1] != '#' && s[i][dy2] != '#')) {
          ok = false;
        }
      }
    }
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;
  return 0;
}

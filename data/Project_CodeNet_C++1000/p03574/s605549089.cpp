#include <bits/stdc++.h>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<string> s(h);
  rep(i, h) std::cin >> s[i];

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '.') {
        s[i][j] = '0';
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            int nx = i + dx, ny = j + dy;
            if (0 <= nx && nx < h && 0 <= ny && ny < w) {
              if (s[i + dx][j + dy] == '#') {
                s[i][j]++;
              }
            }
          }
        }
      }
    }
  }

  rep(i, h) { std::cout << s[i] << std::endl; }

  return 0;
}

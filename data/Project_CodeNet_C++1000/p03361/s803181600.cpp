#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vs;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }

  int mv_x[4] = {-1, 0, 1, 0};
  int mv_y[4] = {0, 1, 0, -1};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (vs[i][j] == '#') {
        bool ok = false;
        for (int k = 0; k < (int)(sizeof(mv_x) / sizeof(int)); k++) {
          int x = i + mv_x[k];
          int y = j + mv_y[k];
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          if (vs[x][y] == '#') {
            ok = true;
            break;
          }
        }
        if (!ok) {
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  return 0;
}
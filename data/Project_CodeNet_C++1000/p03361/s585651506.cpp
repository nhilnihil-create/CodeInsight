#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  string G[h];
  for (int i = 0; i < h; i++) cin >> G[i];

  const int dy[4] = {-1, 0, 0, 1};
  const int dx[4] = {0, -1, 1, 0};

  bool can = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (G[i][j] == '#') {
        bool sharp = false;
        for (int d = 0; d < 4; d++) {
          if (i + dy[d] < 0 || h <= i + dy[d]) continue;
          if (j + dx[d] < 0 || w <= j + dx[d]) continue;
          if (G[i + dy[d]][j + dx[d]] == '#') sharp = true;
        }
        if (sharp == false) can = false;
      }
    }
  }

  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
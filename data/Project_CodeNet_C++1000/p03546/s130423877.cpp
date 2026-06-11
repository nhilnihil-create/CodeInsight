#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  int g[10][10];
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j)
      cin >> g[i][j];
  }
  for (int k = 0; k < 10; ++k) {
    for (int u = 0; u < 10; ++u) {
      for (int v = 0; v < 10; ++v)
        g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
    }
  }
  int64_t ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int x;
      cin >> x;
      if (x >= 0)
        ans += g[x][1];
    }
  }
  cout << ans << '\n';
}

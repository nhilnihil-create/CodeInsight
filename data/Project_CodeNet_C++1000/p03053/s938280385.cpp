#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using GraphC = vector<vector<char>>;
using GraphI = vector<vector<int>>;
using pint = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  GraphC g(h, vector<char>(w));
  rep(y, h) rep(x, w) cin >> g[y][x];

  // 多点をスタートとして扱う
  GraphI d(h, vector<int>(w, -1));
  queue<pint> q;
  rep(y, h) {
    rep(x, w) {
      if (g[y][x] == '#') {
        d[y][x] = 0;
        q.push(pint(y, x));
      }
    }
  }

  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    rep(i, 4) {
      int ny, nx;
      ny = now.first + dy[i];
      nx = now.second + dx[i];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (g[ny][nx] == '#') continue;
      if (d[ny][nx] != -1) continue;
      d[ny][nx] = d[now.first][now.second] + 1;
      q.push(pint(ny, nx));
    }
  }

  int ans = 0;
  rep(y, h) rep(x, w) ans = max(ans, d[y][x]);

  cout << ans << endl;

  return 0;
}

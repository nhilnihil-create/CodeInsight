#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  auto is_range = [&](int x, int y) {
    return (0 <= x) && (x < h) && (0 <= y) && (y < w);
  };

  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {-1, 1, 0, 0};

  vector<vector<int>> d(h, vector<int>(w, -1));

  queue<P> q;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') {
      q.push(P(i, j));
      d[i][j] = 0;
    }
  }

  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    q.pop();
    rep(i, 4) {
      int nx = cx + dx[i], ny = cy + dy[i];
      if (is_range(nx, ny) && d[nx][ny] == -1) {
        d[nx][ny] = d[cx][cy] + 1;
        q.push(P(nx, ny));
      }
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, d[i][j]);
  cout << ans << endl;

  return 0;
}

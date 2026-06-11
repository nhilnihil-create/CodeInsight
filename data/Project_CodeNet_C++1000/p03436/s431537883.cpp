#include <bits/stdc++.h>
using namespace std;

#define reps(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)
const int INF = 0x3f3f3f3f;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int cnt = 0;
  rep(i, h) cin >> s[i];
  rep(i, h) rep(j, w) cnt += (s[i][j] == '#');

  auto in = [&](int i, int j) -> bool {
    return 0 <= i && i < h && 0 <= j && j < w;
  };

  const int dy[] = {0, 1, 0, -1};
  const int dx[] = {1, 0, -1, 0};

  queue<pair<int, int>> que;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  que.emplace(0, 0);
  dist[0][0] = 0;
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int y = p.first, x = p.second;
    rep(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (!in(ny, nx) || s[ny][nx] == '#') continue;
      if (dist[y][x] + 1 < dist[ny][nx]) {
        dist[ny][nx] = dist[y][x] + 1;
        que.emplace(ny, nx);
      }
    }
  }
  if (dist[h - 1][w - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << h * w - dist[h - 1][w - 1] - cnt - 1 << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int INF = 1e7;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
  int h, w;
  cin >> h >> w;
  V<string> g(h);
  rep(i, h) cin >> g[i];

  using S = tuple<int, int, int>;
  priority_queue<S, V<S>, greater<S>> q;

  V<V<int>> c(h + 1, V<int>(w + 1, INF));

  q.push({0, 0, 0});
  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    auto d = get<0>(e) + 1;
    rep(i, 4) {
      int x = get<1>(e) + dx[i];
      int y = get<2>(e) + dy[i];
      if (x < 0 || x >= w) continue;
      if (y < 0 || y >= h) continue;
      if (g[y][x] == '#') continue;
      if (d < c[y][x]) {
        c[y][x] = d;
        q.push({d, x, y});
      }
    }
  }
  if (c[h - 1][w - 1] == INF) {
    cout << -1 << endl;
    return 0;
  }
  int cnt = 0;
  rep(i, h) rep(j, w) if (g[i][j] == '.') cnt++;
  int ans = cnt - (c[h - 1][w - 1] + 1);
  cout << ans << endl;
}

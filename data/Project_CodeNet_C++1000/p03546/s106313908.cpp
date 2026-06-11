#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int INF = 1e6;
V<V<int>> c(10, V<int>(10, 0));

int distance(int src) {
  V<int> r(10, INF);
  priority_queue<P, V<P>, greater<P>> q;

  q.push({0, src});
  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    rep(i, 10) {
      if (i == e.second) continue;
      int dist = e.first + c[e.second][i];
      if (dist < r[i]) {
        r[i] = dist;
        q.push({dist, i});
      }
    }
  }
  return r[1];
}

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, 10) rep(j, 10) cin >> c[i][j];

  V<V<int>> a(h, V<int>(w, 0));
  rep(i, h) rep(j, w) cin >> a[i][j];

  V<int> cost(10, 0);
  rep(i, 10) cost[i] = distance(i);

  int ans = 0;
  rep(i, h) rep(j, w) {
    if (a[i][j] == -1 || a[i][j] == 1) continue;
    ans += cost[a[i][j]];
  }
  cout << ans << endl;
}

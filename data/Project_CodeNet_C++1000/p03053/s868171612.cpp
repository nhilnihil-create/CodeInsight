#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i, 0, h) cin >> v[i];

  queue<P> q;
  vector<vector<int>> mp(h, vector<int>(w, 1e9));
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (v[i][j] == '#') {
        q.push(make_pair(i, j));
        mp[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int y = p.first, x = p.second;
    rep(i, 0, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w)
        continue;
      if (v[ny][nx] == '#' || mp[ny][nx] != 1e9)
        continue;
      chmin(mp[ny][nx], mp[y][x] + 1);
      q.push(make_pair(ny, nx));
    }
  }

  int ans = 0;
  rep(i, 0, h) {
    rep(j, 0, w) { chmax(ans, mp[i][j]); }
  }

  cout << ans << endl;
}

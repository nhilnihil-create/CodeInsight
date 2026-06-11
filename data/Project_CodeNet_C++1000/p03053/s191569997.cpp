#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;

const int INF = 100000000;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int W, int H, vector<string>& A, vector<vector<int>>& d) {
  queue<P> que;

  rep(y, H) rep(x, W) {
    if (A[y][x] == '#') {
      que.push(P(x, y));
      d[y][x] = 0;
    }
  }

  while (que.size()) {
    P p = que.front(); que.pop();
    rep(i, 4) {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      if (0 <= nx && nx < W && 0 <= ny && ny < H &&
          A[ny][nx] != '#' && d[ny][nx] == INF) {
        que.push(P(nx, ny));
        d[ny][nx] = d[p.second][p.first] + 1;
      }
    }
  }
}


int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  rep(i, H) cin >> A[i];
  
  vector<vector<int>> d(H, vector<int>(W, INF));
  bfs(W, H, A, d);

  int ans = 0;
  rep(i, H) rep(j, W) ans = max(ans, d[i][j]);

  cout << ans << endl;
  
  return 0;
}
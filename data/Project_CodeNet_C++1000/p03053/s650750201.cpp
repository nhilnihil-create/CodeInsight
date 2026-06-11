#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  char field[h][w];
  int d[h][w];
  queue<P> que;
  rep(i,h) rep(j,w) {
    cin >> field[i][j];
    d[i][j] = -1;
    if (field[i][j] == '#') {
      que.push(P(i, j));
      d[i][j] = 0;
    }
  }

  while (!que.empty()) {
    P p = que.front(); que.pop();

    rep(i,4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx < 0 || h <= nx) continue;
      if (ny < 0 || w <= ny) continue;
      if (field[nx][ny] == '#') continue;
      if (d[nx][ny] != -1) continue;
      que.push(P(nx, ny));
      d[nx][ny] = d[p.first][p.second] + 1;
    }
  }

  int res = 0;
  rep(i,h) rep(j,w) res = max(res, d[i][j]);
  cout << res << endl;
  return 0;
}

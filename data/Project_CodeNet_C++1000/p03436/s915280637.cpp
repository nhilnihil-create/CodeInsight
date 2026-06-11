#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e9;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> s[i][j];

  queue<P> Q;
  vector<vector<int>> d(h, vector<int>(w, INF));
  d[0][0] = 1;
  Q.push(make_pair(0, 0));
  while (Q.size()) {
    P p = Q.front();
    Q.pop();
    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (s[nx][ny] == '#' || d[nx][ny] != INF) continue;
      d[nx][ny] = d[p.first][p.second] + 1;
      Q.push(make_pair(nx, ny));
    }
  }
  int cw = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '.') ++cw;
  int ans = -1;
  if (d[h-1][w-1] != INF) ans = cw - d[h-1][w-1];
  cout << ans << endl;
  return 0;
}
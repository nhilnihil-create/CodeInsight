#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e8;
const int H = 1000, W = 1000;

int h, w;
char a[H][W];

int d[H][W];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) d[i][j] = INF;
  queue<P> que;
  rep(i, h) rep(j, w) if (a[i][j] == '#') {
    que.push(make_pair(i, j));
    d[i][j] = 0;
  }
  while (que.size()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (d[nx][ny] > d[x][y] + 1) {
        que.push(make_pair(nx, ny));
        d[nx][ny] = d[x][y] + 1;
      }
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, d[i][j]);
  cout << ans << endl;
  return 0;
}
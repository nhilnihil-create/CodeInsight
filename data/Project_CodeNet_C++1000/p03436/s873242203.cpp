#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e8;
const int H = 50, W = 50;

int h, w;
char s[H][W];

int d[H][W];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> s[i][j];
  rep(i, h) rep(j, w) d[i][j] = INF;
  queue<P> que;
  d[0][0] = 1;
  que.push(make_pair(0, 0));
  while (que.size()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (s[nx][ny] == '#') continue;
      if (d[nx][ny] > d[x][y] + 1) {
        d[nx][ny] = d[x][y] + 1;
        que.push(make_pair(nx, ny));
      }
    }
  }
  if (d[h - 1][w - 1] == INF) {
    cout << -1 << endl;
    return 0;
  }
  int ans = -d[h - 1][w - 1];
  rep(i, h) rep(j, w) if (s[i][j] == '.') ans++;
  cout << ans << endl;
  return 0;
}
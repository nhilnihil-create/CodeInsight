#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
char maze[60][60];
int main() {
  int h, w;
  cin >> h >> w;
  int white_cnt = 0;
  rep(i,h) rep(j,w) {
    cin >> maze[i][j];
    if (maze[i][j] == '.') white_cnt++;
  }
  int dist[60][60];
  memset(dist, -1, sizeof(dist));
  dist[0][0] = 0;

  queue<P> p;
  p.push(make_pair(0,0));
  int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
  while (!p.empty())
  {
    int x = p.front().first, y = p.front().second;
    p.pop();
    rep(i,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (0<=nx&&nx<h&&0<=ny&&ny<w&&maze[nx][ny]=='.') {
        if (dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[x][y] + 1;
        p.push(make_pair(nx, ny));
      }
    }
  }
  if (dist[h-1][w-1]>0) cout << white_cnt - dist[h-1][w-1] - 1 << endl;
  else cout << -1<< endl;
  return 0;
}
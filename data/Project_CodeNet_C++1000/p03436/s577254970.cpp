#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e6;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  REP(i, H) { cin >> s[i]; }
  vector<vector<int>> dis(H, vector<int>(W, -INF));
  queue<P> que;
  que.push(P(0, 0));
  dis[0][0] = 1;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    int y = p.first, x = p.second;
    if (0 < x) {
      int nx = x - 1, ny = y;
      if (s[ny][nx] == '.') {
        if (dis[ny][nx] == -INF) {
          dis[ny][nx] = dis[y][x] + 1;
          que.push(P(ny, nx));
        }
      }
    }
    if (x < W - 1) {
      int nx = x + 1, ny = y;
      if (s[ny][nx] == '.') {
        if (dis[ny][nx] == -INF) {
          dis[ny][nx] = dis[y][x] + 1;
          que.push(P(ny, nx));
        }
      }
    }
    if (0 < y) {
      int nx = x, ny = y - 1;
      if (s[ny][nx] == '.') {
        if (dis[ny][nx] == -INF) {
          dis[ny][nx] = dis[y][x] + 1;
          que.push(P(ny, nx));
        }
      }
    }
    if (y < H - 1) {
      int nx = x, ny = y + 1;
      if (s[ny][nx] == '.') {
        if (dis[ny][nx] == -INF) {
          dis[ny][nx] = dis[y][x] + 1;
          que.push(P(ny, nx));
        }
      }
    }
  }
  if (dis[H - 1][W - 1] == -INF) {
    cout << -1 << endl;
    return 0;
  }
  ll tmp = 0;
  REP(i, H) REP(j, W) {
    if (s[i][j] == '.') tmp++;
  }
  cout << tmp - dis[H - 1][W - 1] << endl;
}
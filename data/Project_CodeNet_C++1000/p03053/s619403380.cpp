#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W;
  cin >> H >> W;
  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  int dist[H][W];
  char A[H][W];
  queue<P> que;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      if (A[i][j] == '#') {
        dist[i][j] = 0;
        que.push(make_pair(i,j));
      } else {
        dist[i][j] = 1000000;
      }
    }
  }
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int x = p.first + dx[i];
      int y = p.second + dy[i];
      if (0 <= x && x < H && 0 <= y && y < W) {
        if (dist[x][y] > dist[p.first][p.second] + 1) {
          dist[x][y] = dist[p.first][p.second] + 1;
          que.push(make_pair(x,y));
        }
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans,dist[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
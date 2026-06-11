#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int H,W;
char field[60][60];
int dis[60][60];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void BFS() {
  dis[0][0] = 0;
  queue<P> que;
  que.push(make_pair(0,0));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.F + dx[i];
      int ny = p.S + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W) {
        if (field[nx][ny] == '.' && dis[nx][ny] > dis[p.F][p.S] + 1) {
          dis[nx][ny] = dis[p.F][p.S] + 1;
          que.push(make_pair(nx,ny));
        }
      }
    }
  }
  return ;
}

int main() {
  cin >> H >> W;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      if (field[i][j] == '.') {
        cnt++;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      dis[i][j] = 99999999;
    }
  }
  BFS();
  ans = cnt - dis[H-1][W-1] - 1;
  if (dis[H-1][W-1] == 99999999) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
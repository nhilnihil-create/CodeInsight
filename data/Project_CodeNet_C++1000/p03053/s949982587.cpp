#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int h,w;
char maze[1010][1010];
int d[1010][1010];
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      d[i][j] = -1;
    }
  }
  for (int i = 0; i < h; i++) {
    cin >> maze[i];
  }
  queue<pair<int,int>> que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (maze[i][j] == '#') {
        d[i][j] = 0;
        que.push({i,j});
      }
    }
  }
  int ans = 0;
  while (!que.empty()) {
    pair<int,int> tp = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int th = tp.first + dh[i];
      int tw = tp.second + dw[i];
      if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
      if (d[th][tw] != -1) continue;
      d[th][tw] = d[tp.first][tp.second] + 1;
      ans = max(ans, d[th][tw]);
      que.push({th,tw});
    }
  }
  cout << ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
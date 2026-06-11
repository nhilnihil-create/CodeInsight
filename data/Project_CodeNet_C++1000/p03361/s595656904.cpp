#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int H,W; cin>>H>>W;
  string board[H];
  rep(i,H) cin>>board[i];

  string ans = "Yes";
  rep(i, H) {
    rep(j, W) {
      if (board[i][j] == '#') {
        bool can = false;
        // 上下チェック
        for (int dy = -1; dy < 2; dy++) {
          int ny = i + dy;
          if (ny >= 0 && ny < H) {
            if (i != ny && board[ny][j] == '#') can = true;
          }
        }
        // 左右チェック
        for (int dx = -1; dx < 2; dx++) {
          int nx = j + dx;
          if (nx >= 0 && nx < W) {
            if (j != nx && board[i][nx] == '#') can = true;
          }
        }
        if (can == false) {
          ans = "No";
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
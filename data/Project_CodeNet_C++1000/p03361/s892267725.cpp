#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> board(H);
  rep(i,0,H-1) cin >> board[i];

  string ans = "Yes";
  rep(i,0,H-1) {
    rep(j,0,W-1) {
      if (board[i][j] == '.') continue;

      bool ok = false;
      if (0 <= i - 1) {
        if (board[i-1][j] == '#') ok = true;
      }

      if (i + 1 < H) {
        if (board[i+1][j] == '#') ok = true;
      }

      if (0 <= j - 1) {
        if (board[i][j-1] == '#') ok = true;
      }

      if (j + 1 < W) {
        if (board[i][j+1] == '#') ok = true;
      }

      if (!ok) ans = "No";
    }
  }

  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int H, W;cin>>H>>W;
  string board[H];
  rep(i,H)cin>>board[i];

  rep(i, H) {
    rep(j, W) {
      if (board[i][j] == '.') {
        board[i][j] = '0';
        for(int dy = -1; dy < 2; dy ++) {
          for(int dx = -1; dx < 2; dx++) {
            int ny = i+dy, nx = j+dx;
            if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
              if (board[ny][nx] == '#') board[i][j]++;
            }
          }
        }
      }
    }
  }

  rep(i, H) cout << board[i] << endl;
  return 0;
}
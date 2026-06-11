#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> board(h);
  rep(i, h) cin >> board[i];
  vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
  vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  
  rep(i, h) rep(j, w) {
    if(board[i][j] == '#') continue;
    int cnt = 0;
    rep(d, 8) {
      int yi = i + dy[d];
      int xj = j + dx[d];
      if(yi < 0 || yi >= h) continue;
      if(xj < 0 || xj >= w) continue;
      if(board[yi][xj] == '#') cnt++;
    }
    board[i][j] = char(cnt + '0');
  }
  
  rep(i, h) cout << board[i] << endl;
  return 0;
}
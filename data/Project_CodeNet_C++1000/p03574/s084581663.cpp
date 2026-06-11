#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int H, W;
  cin >> H >> W;

  string board[H];
  rep(i,H) cin >> board[i];

  const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
  const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

  rep(i,H){
    rep(j,W){
      if (board[i][j] == '#') continue;

      int num = 0;//爆弾が周囲8方向に隣接する個数
      rep(d,8){
        int newi = i + dx[d];//解説ではconst int になっているが？
        int newj = j + dy[d];

        if(newi < 0 || newi >= H) continue;
        if(newj < 0 || newj >= W) continue;
        if (board[newi][newj] == '#') num++;
      }
      board[i][j] = char(num + '0');
    }
  }
  rep(i,H) cout << board[i] << endl;
}

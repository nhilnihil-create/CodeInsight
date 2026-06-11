#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H); //H個の文字列
  for(int i = 0; i < H; i++){
    cin >> S[i];
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){

      if(S[i][j] == '.'){ //もし空きマスなら0にする
        S[i][j] = '0';

        for(int dx = -1; dx <= 1; dx++){ // 変数dxを-1,0,1で回す
          for(int dy = -1; dy <= 1; dy++){
            int nx = i + dx,  ny = j + dy;
            // i,j と足すことで周囲八方を確認するためのnx,nyを用意
            if(0 <= nx && nx < H && 0 <= ny && ny < W){
              if(S[nx][ny] == '#') S[i][j]++;
              //  もし爆弾マスなら元のマスをインクリメント
            }
          }
        }
      }
    }
  }
  for(int i = 0; i < H; i++){
    cout << S[i] << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char S[H][W];
  //入力
  for( int i = 0; i < H; ++i ){
    for( int j = 0; j < W; ++j ){
      cin >> S[i][j];
    }
  }
  
  //出力
  for( int i = 0; i < H; ++i ){
    for( int j = 0; j < W; ++j ){
      int count = 0;
      if( S[i][j] == '#' ){
        cout << '#';
        continue;
      }
      //自マスの左上に爆弾があるか
      if( S[i - 1][j - 1] == '#' ){
        if( i - 1 >= 0 && j - 1 >= 0 ){
          ++count;
        }
      }
      //自マスの上に爆弾があるか
      if( S[i - 1][j] == '#' ){
        if( i - 1 >= 0 ){
          ++count;
        }
      }
      //自マスの右上に爆弾があるか
      if( S[i - 1][j + 1] == '#' ){
        if( i - 1 >= 0 && j + 1 < W ){
          ++count;
        }
      }
      //自マスの左に爆弾があるか
      if( S[i][j - 1] == '#' ){
        if( j - 1 >= 0 ){
          ++count;
        }
      }
      //自マスの右に爆弾があるか
      if( S[i][j + 1] == '#' ){
        if( j + 1 < W ){
          ++count;
        }
      }
      //自マスの左下に爆弾があるか
      if( S[i + 1][j - 1] == '#' ){
        if( i + 1 < H && j - 1 >= 0 ){
          ++count;
        }
      }
      //自マスの下に爆弾があるか
      if( S[i + 1][j] == '#' ){
        if( i + 1 < H ){
          ++count;
        }
      }
      //自マスの右下に爆弾があるか
      if( S[i + 1][j + 1] == '#' ){
        if( i + 1 < H && j + 1 < W ){
          ++count;
        }
      }
      cout << count;
    }
    cout << endl;
  }
}

#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int H,W;
  cin >> H >> W;
  
  char board[52][52];
  //範囲外の条件分岐がめんどくさいので上下左右に１マス余裕をもって入力しておく。
  for(int i = 1; i <= H; i++){
    for(int j = 1; j <= W; j++)cin >> board[i][j];
  }
  
  //問題文を言い換えると、上下左右どこにも隣接したマスがない部分があったらNoを出力ということになる
  for(int i = 1; i<= H; i++){
    for(int j = 1; j <= W; j++){
      if(board[i][j] == '#'){
        if(board[i-1][j] != '#' && board[i][j-1] != '#' && board[i][j+1] != '#' && board[i+1][j]!= '#' ){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
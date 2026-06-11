#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  string board[50];
  cin >> h >> w;
  int dw[8] = {1,1,0,-1,-1,-1,0,1};
  int dh[8] = {0,1,1,1,0,-1,-1,-1};
  for(int i=0;i<h;i++){
    cin >> board[i];
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(board[i][j] == '.'){
        int count=0;
        for(int k=0;k<8;k++){
          int x = j + dw[k];
          int y = i + dh[k];
          if(x>=0 && x <w && y>=0 && y<h && board[y][x] == '#'){
            count++;
          }
          board[i][j] = '0' + count;
        }
      }
    }
  }
  for(int i=0;i<h;i++){
    cout << board[i] << endl;
  }
  return 0;
}
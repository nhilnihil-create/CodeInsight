#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  string board[50];
  
  for (int i=0; i<h; i++) cin >> board[i];
  
  const int x[8]={1,1,1,0,-1,-1,-1,0};
  const int y[8]={-1,0,1,1,1,0,-1,-1};
  
  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      if (board[i][j]=='#') continue;
      
      int num=0;
      for (int d=0; d<8; d++){
        const int ni =i+x[d];
        const int nj =j+y[d];
        
        if (ni<0 || h<=ni) continue;
        if (nj<0 || w<=nj) continue;
        if (board[ni][nj]=='#') num++;
      }
      
      board[i][j]=char(num+'0');
    }
  }
  
  for (int i=0; i<h; i++) cout << board[i] << endl;
}

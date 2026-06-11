#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

main(){
  int h,w;cin >> h >> w;
  string board[h];for(int i=0;i<h;i++) cin >> board[i];
  const int dy[4]={0,1,0,-1};
  const int dx[4]={1,0,-1,0};
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(board[i][j] == '.') continue;
      
      if(board[i][j] == '#'){
        bool check = false;
        for(int k=0;k<4;k++){
          int ny = j + dy[k];
          int nx = i + dx[k];
          if(ny<0 || ny>=w) continue;
          if(nx<0 || nx>=h) continue;
          if (board[nx][ny] == '#'){
            check = true;
          }
        }
        if(check){
          continue;
        } else {
          cout << "No" << endl;
          return 0;
        }
      }
      
    }
  }
  cout << "Yes" << endl;
  return 0;
}



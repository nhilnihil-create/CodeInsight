#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  
  string board[50];
  for(int i=0;i<H;i++){
    cin >> board[i];
  }
  
  vector<int> dx={1,-1,1,-1,0,0,1,-1};
  vector<int> dy={0,0,1,-1,1,-1,-1,1};
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> board[i][j];
      if(board[i][j]=='.'){
        int cnt=0;
        for(int k=0;k<8;k++){
          int x=i+dx[k],y=j+dy[k];
          if(x<0 || x>=H || y<0 || y>=W){
            continue;
          }
          if(board[x][y]=='#'){
            cnt++;
          }
        }
        board[i][j]=char(cnt+'0');
      }
    }
  }
  
  for(int i=0;i<H;i++){
    cout << board[i] <<endl;
  }
}

  
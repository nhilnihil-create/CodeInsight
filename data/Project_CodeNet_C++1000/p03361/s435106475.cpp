#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  
  string board[50];
  for(int i=0;i<N;i++){
    cin >> board[i];
  }
  
  vector<int> dx={0,0,1,-1};
  vector<int> dy={1,-1,0,0};
  
  bool can=true;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(board[i][j]=='#'){
        int cnt=0;
        for(int k=0;k<4;k++){
          int x=i+dx[k];
          int y=j+dy[k];
          if(x<0||x>=N||y<0||y>=M){
            continue;
          }
          if(board[x][y]=='#'){
            break;
          }
          if(k==3){
            can=false;
          }
        }
      }
        
      if(!can){
        break;
      }
    }
    if(!can){
      break;
    }
  }

  if(can){
      cout << "Yes" <<endl;
  }
  else{
    cout << "No" <<endl;
  }
}

      
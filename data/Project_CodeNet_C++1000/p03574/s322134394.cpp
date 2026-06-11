#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>vec[i][j];
    }
  }
  
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int check=0;
      if(vec[i][j]=='.'){
        vec[i][j]='0';
        for(int dx=-1;dx<=1;dx++){
          for(int dy=-1;dy<=1;dy++){
          int nx=i+dx,ny=j+dy;
          if(0<=nx&&nx<H&&0<=ny&&ny<W&&vec[nx][ny]=='#'){
            vec[i][j]++;
          }
          }
        }
      }
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<vec[i][j];
    }
    cout<<endl;
  }
}
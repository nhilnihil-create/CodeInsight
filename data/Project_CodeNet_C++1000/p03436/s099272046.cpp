#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  int x,y;
  int nx,ny;
  int count=0;
  cin>>h>>w;
  int f[h][w];
  vector<int>xx={1,0,-1,0};
  vector<int>yy={0,1,0,-1};
  int inf=10000000;
  queue<pair<int,int>>q;
  char c;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c;
      if(c=='.'){
        f[i][j]=inf;
      }
      else {
        f[i][j]=0;
        count++;
      }
    }
  }
  q.push(pair(0,0));
  f[0][0]=0;
  while(q.size()>0){
    tie(x,y)=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      nx=x+xx[i];
      ny=y+yy[i];
      if(nx<0||ny<0||nx>=w||ny>=h)continue;
      if(f[ny][nx]==0)continue;
      if(f[ny][nx]>f[y][x]+1){
        f[ny][nx]=f[y][x]+1;
        q.push(pair(nx,ny));
      }      
    }
  }
  if(f[h-1][w-1]==inf){
    cout<<-1;
  }else{
    cout<<h*w-f[h-1][w-1]-count-1;
  }
  
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  int ans=1;
  cin>>H>>W;
  char C[H][W];
  int S[H][W];
  string M;
  queue<pair<int,int>>que;
  for(int i=0;i<H;i++){
    cin>>M;
    for(int j=0;j<W;j++){
      C[i][j]=M.at(j);
      if(C[i][j]=='.'){
        S[i][j]=0;
      }
      else{
        S[i][j]=1;
        que.push(pair<int,int>(i,j));
      }
    }
  }
  while(que.size()){
      pair<int,int> p=que.front();que.pop(); 
      int nx=p.first,ny=p.second;
    
      if(nx-1>=0 && S[nx-1][ny]==0){
      S[nx-1][ny]=S[nx][ny]+1;
      que.push(pair<int,int>(nx-1,ny));
      }
      if(ny-1>=0 && S[nx][ny-1]==0){
        S[nx][ny-1]=S[nx][ny]+1;
        que.push(pair<int,int>(nx,ny-1));
      }   
      if(ny+1<W && S[nx][ny+1]==0){
        S[nx][ny+1]=S[nx][ny]+1;
        que.push(pair<int,int>(nx,ny+1));
      }
      if(nx+1<H && S[nx+1][ny]==0){
        S[nx+1][ny]=S[nx][ny]+1;
        que.push(pair<int,int>(nx+1,ny));
      }  
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      //cout<<S[i][j];
      ans=max(ans,S[i][j]);
    }
    //cout<<endl;
  }
  
  cout<<ans-1<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
const int val=1000000;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(void){
  int h,w;
  int ans=0;
  cin>>h>>w;
  char a[h][w];
  int num[h][w];
  queue<P> que;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      if(a[i][j]=='#'){
        que.push(P(i,j));
        num[i][j]=0;
      }else{
        num[i][j]=val;
      }
    }
  }
  while(que.size()){
    P p=que.front();
    que.pop();
    for(int i=0;i<4;i++){
      int nx=p.first+dx[i],ny=p.second+dy[i];
      if(0<=nx && nx<h && 0<=ny && ny<w && num[nx][ny]==val){
        num[nx][ny]=num[p.first][p.second]+1;
        que.push(P(nx,ny));
        ans=max(ans,num[nx][ny]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
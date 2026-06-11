#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string> data(H);
  for(int i=0;i<H;i++){
    cin>>data.at(i);
  }
   // cout<<"AA"<<endl;
  vector<vector<int>> dist(H,vector<int>(W,-1));
  using pir=pair<int,int>;
  queue<pir> que;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data[i][j]=='#'){
        dist[i][j]=0;
        que.push(pir(i,j));
      }
    }
  }
  //cout<<"AA"<<endl;
  int dx[4]={0,0,1,-1};
  int dy[4]={1,-1,0,0};
  while(!que.empty()){
    auto cp=que.front();
    que.pop();
    for(int i=0;i<4;i++){
      int nx=cp.second+dx[i];
      int ny=cp.first+dy[i];
      if(nx<0||nx>=W||ny<0||ny>=H)  continue;
      if(dist[ny][nx]==-1){
        dist[ny][nx]=dist[cp.first][cp.second]+1;
        que.push(pir(ny,nx));
      }
    }
  }

  int tmp=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      tmp=max(tmp,dist[i][j]);
    }
  }
  cout<<tmp<<endl;
  return 0;
}
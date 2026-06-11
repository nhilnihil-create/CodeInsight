#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string>data(H);
  int count=0;
  for(int i=0;i<H;i++)cin>>data[i];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data[i][j]=='#')
      count++;
    }
  }

  vector<vector<int>>dist(H,vector<int>(W,-1));
  using pir=pair<int,int>;
  queue<pir> que;

  dist[0][0]=1;
  que.push(pir(0,0));

  int dx[4]={0,0,1,-1};
  int dy[4]={1,-1,0,0};
  while(!que.empty()){
    auto v=que.front();
    que.pop();
    for(int i=0;i<4;i++){
      int nx=v.second+dx[i];
      int ny=v.first+dy[i];
      if(nx<0||nx>=W||ny<0||ny>=H)continue;
      if(dist[ny][nx]!=-1)continue;
      if(data[ny][nx]=='#')continue;
      dist[ny][nx]=dist[v.first][v.second]+1;
      que.push(pir(ny,nx));
    }
  }
  if(dist[H-1][W-1]==-1){
    cout<<-1<<endl;
    return 0;
  }
  int ans=H*W-dist[H-1][W-1]-count;
  cout<<ans<<endl;
}

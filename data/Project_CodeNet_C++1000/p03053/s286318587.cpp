#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string> data(H);
  for(int i=0;i<H;i++){
    cin>>data[i];
  }
  //vector<vector<int>>dist(H,vector<int>(W,10000));
  queue<pair<int,int>> que;
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
  //初期状態
  int cnt=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data[i][j]=='#'){
        que.push(make_pair(i,j));
        cnt++;
      }
    }
  }

  //BFS
  int next_turn=0;
  int ans=0;
  while(!que.empty()){
    auto v=que.front();
    que.pop();
    cnt--;
    for(int i=0;i<4;i++){
      int nx=v.second+dx[i];
      int ny=v.first+dy[i];
      if(nx<0||nx>=W||ny<0||ny>=H)continue;
      if(data[ny][nx]=='#')continue;
      data[ny][nx]='#';
      que.push(make_pair(ny,nx));
      next_turn++;
    }
          if(cnt==0){
        cnt=next_turn;
        next_turn=0;
        ans++;
      }
  }
  cout<<ans-1<<endl;
}
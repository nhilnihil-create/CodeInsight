#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using P = pair<ll,ll>;
using Graph =vector<string>;
Graph field;
queue<P> q;

int main() {
  int h,w,ans=-1;
  cin>>h>>w;
  field.resize(h);
  rep(i,h)cin>>field[i];
  vector<vector<int>> dist(h,vector<int>(w,-1));

  rep(i,h)rep(j,w){
    if(field[i][j]=='#'){
      q.push(make_pair(i,j));
    }
  }
  int dx[4]={0,0,-1,1};
  int dy[4]={1,-1,0,0};
  while(!q.empty()){
    P ab=q.front();
    int x=ab.first;
    int y=ab.second;
    q.pop();
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<0||ny<0||nx>=h||ny>=w)continue;
      if(field[nx][ny]!='.')continue;
      if(field[nx][ny]!='#'&&dist[nx][ny]==-1){
      dist[nx][ny]=dist[x][y]+1;
      q.push(make_pair(nx,ny));
      ans=max(dist[nx][ny],ans);
      }
    }
  }
  cout<<ans+1<<endl;
}

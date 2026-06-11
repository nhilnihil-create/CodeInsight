#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//解説AC
int dist[55][55];
char masu[55][55];
int vx[4]={0,1,0,-1};
int vy[4]={1,0,-1,0};
int r,c,sy,sx,gy,gx;
int main() {
  int batu=0;
  
  cin >>r>>c;
  sy=0;
  sx=0;
  gy=r-1;
  gx=c-1;
  rep(i,r){
    rep(j,c){
      cin>>masu[i][j];
      dist[i][j]=-1;
      if(masu[i][j]=='#')batu++;
    }
  }
  dist[sy][sx]=0;
  queue<pair<int,int>>q;
  q.push(make_pair(sy,sx));
  while(!q.empty()){
    pair<int,int>p=q.front();q.pop();
    int y=p.first;
    int x=p.second;
    rep(i,4){
      int ny=y+vy[i];
      int nx=x+vx[i];
      if(nx<0||nx>c||ny<0||ny>r)continue;
      if(masu[ny][nx]=='#')continue;
      if(dist[ny][nx]==-1){
        dist[ny][nx]=dist[y][x]+1;
        q.push(make_pair(ny,nx));
      }
    }
  }
  if(dist[gy][gx]==-1){
    cout<<-1<<endl;
    return 0;
  }
  int kotae=r*c-dist[gy][gx]-batu-1;
  cout<<kotae<<endl;
  /*rep(i,r){
    rep(j,c){
      cout<<masu[i][j]<<" ";
    }
    cout<<endl;
  }
  rep(i,r){
    rep(j,c){
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return 0;
}
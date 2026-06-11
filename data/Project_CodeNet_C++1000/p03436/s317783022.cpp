#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

char grid[55][55];
int dist[55][55];
const int INF=INT_MAX;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};

int main(){
  int h,w;
  cin>>h>>w;
  int black=0;
  rep(i,h)rep(j,w){
    cin>>grid[i][j];
    dist[i][j]=INF;
    if(grid[i][j]=='#') black++;
  }
  dist[0][0]=0;
  queue<P> q;
  q.push(make_pair(0,0));
  while(!q.empty()){
    int pi,pj;
    tie(pi,pj)=q.front(); q.pop();
    int past = dist[pi][pj];
    rep(tmp,4){
      int now=past+1;
      int ni=pi+di[tmp],nj=pj+dj[tmp];
      if(grid[ni][nj]=='#') continue;
      if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
      if(dist[ni][nj]<=now) continue;
      dist[ni][nj]=now;
      q.push(make_pair(ni,nj));
    }
  }
  if(dist[h-1][w-1]!=INF) cout<<h*w-black-dist[h-1][w-1]-1<<endl;
  else cout<<-1<<endl;
}


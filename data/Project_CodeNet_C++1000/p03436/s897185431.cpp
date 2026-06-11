#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using P = pair<ll,ll>;
using Graph =vector<string>;

int main() {
int h,w,c;
cin>>h>>w;
Graph g(h);
rep(i,h)cin>>g[i];
rep(i,h)rep(j,w){
  if(g[i][j]=='#')c++;
}
queue<P> q;
vector<vector<int>> dist(h,vector<int>(w,-1)); 
q.push(make_pair(0,0));
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
while(!q.empty()){
  P ab=q.front();
  ll x=ab.first;
  ll y=ab.second;
  q.pop();
  rep(i,4){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<0||ny<0||nx>=h||ny>=w)continue;
    if(g[nx][ny]=='#')continue;
    if(dist[nx][ny]!=-1)continue;
    dist[nx][ny]=dist[x][y]+1;
    q.push(make_pair(nx,ny));
  }
}
if(dist[h-1][w-1]==-1){
  cout<<-1<<endl;
}else{
  cout<<h*w-dist[h-1][w-1]-c-2<<endl;
}
}

#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int main() {
//最短経路を求める問題
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
    rep(i,0,h) cin>>s[i];
  ////////
  int dist[h][w];
  int white=0;
  rep(i,0,h){
    rep(j,0,w) {
      if(s[i][j]=='.') white++; 
      dist[i][j]=-1;
    }
  }
 
  queue<P> bfs;
  dist[0][0]=1;
  bfs.push(mp(0,0));
  while(!bfs.empty()){
    P now=bfs.front();
    bfs.pop();
    int a=now.first;
    int b=now.second;
    rep(i,0,4){
      int na=a+dx[i];
      int nb=b+dy[i];
      if(na<0||nb<0||na>=h||nb>=w||s[na][nb]=='#')continue;
      if(dist[na][nb]!=-1)continue;
      bfs.push(mp(na,nb));
      dist[na][nb]=dist[a][b]+1;
      //cout<<dist[na][nb]<<endl;
    }
  }
  if(dist[h-1][w-1]!=-1){
  white-=dist[h-1][w-1];
 // cout<<dist[0][1]<<endl;
  cout<<white<<endl;
  }
  else cout<<-1<<endl;
}
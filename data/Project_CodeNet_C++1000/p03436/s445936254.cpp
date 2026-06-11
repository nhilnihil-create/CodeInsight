#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H,W;
  cin>>H>>W;
  vector<string> v(H);
  rep(i,H) cin>>v[i];
  int cnta = 0, cntb = 0;
  rep(i,H){
    rep(j,W) {
      if(v[i][j]=='.') cnta++;
      else cntb++;
    }
  }
  queue<P> q;
  q.push(make_pair(0,0));
  vector<vector<bool>> seen(H,vector<bool>(W,false));
  seen[0][0] = true;
  graph g(H,vector<int>(W,-1));
  g[0][0] = 0;
  while(!q.empty()){
    P p = q.front();
    q.pop();
    rep(i,4){
      int nx = p.first+dx[i];
      int ny = p.second+dy[i];
      if(nx<0||nx>=H||ny<0||ny>=W) continue;
      if(seen[nx][ny]) continue;
      if(v[nx][ny]=='#') continue;
      seen[nx][ny] = true;
      g[nx][ny] = g[p.first][p.second]+1;
      q.push(make_pair(nx,ny));
    }
  }
  if(g[H-1][W-1]==-1) cout<<g[H-1][W-1]<<endl;
  else cout<<H*W-g[H-1][W-1]-cntb-1<<endl;
}
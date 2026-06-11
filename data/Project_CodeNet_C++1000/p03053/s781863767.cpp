#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

int main(){
  int H, W; cin >> H >> W;
  vs fld(H);
  rep(i,H) cin >> fld[i];
  
  vvi dist(H, vi(W,-1));
  queue<pii> Q;
  rep(i,H){
    rep(j,W){
      if(fld[i][j]=='#') {Q.push(pii(i,j)); dist[i][j]=0;} 
    }  
  }
  
  while (Q.size()){
    int x = Q.front().first;
    int y = Q.front().second;
    
    rep(i,4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || nx >=H || ny<0 || ny>=W) continue;
      if(fld[nx][ny] == '#') continue;
      fld[nx][ny] = '#';
      dist[nx][ny] = dist[x][y]+1;
      Q.push(pii(nx,ny));
    }
    Q.pop();
  }
  
  int ans = 0;
  rep(i,H)rep(j,W) ans = max(ans, dist[i][j]);
  cout << ans << endl;
  return 0;
}
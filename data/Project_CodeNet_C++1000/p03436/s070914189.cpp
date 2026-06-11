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
  vector<vector<char>> fld(H,vector<char>(W));
  int counts = 0;
  rep(i,H){rep(j,W){ 
    cin >> fld[i][j];
    if(fld[i][j] == '#') counts++;
  }}
  
  vvi dist(H,vi(W,-1));
  queue<pii> que;
  que.push(pii(0,0));
  dist[0][0]= 0;
  while(que.size()){
    int x = que.front().first;
    int y = que.front().second;
    rep(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >=H || ny<0 || ny>=W) continue;
      if(fld[nx][ny]=='#') continue;
      if(dist[nx][ny]== -1){
        dist[nx][ny]=dist[x][y]+1;
        que.push(pii(nx,ny));
      }
    }
    que.pop();
  }
  if(dist[H-1][W-1]== -1) cout << -1 << endl;
  else cout << H*W-counts-dist[H-1][W-1]-1 << endl;
  return 0;
}
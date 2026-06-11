#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int H, W; cin >> H >> W;
  string s[H];
  rep(i,H) cin >> s[i];

  queue<pii> q;
  q.push({0,0});
  vector<vector<int>> dist(H,vector<int>(W,-1));
  dist[0][0] = 1;
  int to_r[4] = {0,0,-1,1};
  int to_c[4] = {1,-1,0,0};

  while(!q.empty()){
    auto now = q.front(); q.pop();
    rep(i,4){
      int row = now.first + to_r[i], col = now.second + to_c[i];
      if (row<0 || row >= H || col<0 || col>=W) continue;
      if (s[row][col]=='.' && dist[row][col]==-1) {
        q.push({row,col});
        dist[row][col] = dist[now.first][now.second] + 1;
      }

    }
  }

  if (dist[H-1][W-1]==-1) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  rep(i,H) rep(j,W) if (s[i][j]=='.') ans++;
  cout << ans - dist[H-1][W-1] << endl;
   

  




  // cout << fixed << setprecision(10);
  
  return 0;
}

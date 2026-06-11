#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,C,inf = 1010;
  cin >> n >> C;
  vector<vector<int>>d(C,vector<int>(C));
  vector<vector<int>>c(n,vector<int>(n));
  rep(i,0,C) rep(j,0,C) cin >> d[i][j];
  rep(i,0,n) rep(j,0,n){
    cin >> c[i][j];
    c[i][j]--;
  }
  vector<vector<int>>sum(3,vector<int>(C));
  rep(i,0,n) rep(j,0,n) rep(k,0,C) sum[(i+j)%3][k] += d[c[i][j]][k];
  int ans = 1e9+7;
  rep(i,0,C) rep(j,0,C){
    if(i == j) continue;
    rep(k,0,C){
      if(i == k || j == k) continue;
      ans = min(ans,sum[0][i]+sum[1][j]+sum[2][k]);
    }
  }
  cout << ans << endl;
}
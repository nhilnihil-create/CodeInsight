#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int h, w;
  cin >> h >> w;
  int f[10][10];
  rep(i,10) {
    rep(j,10) cin >> f[i][j];
  }
  rep(k,10) {
    rep(i,10) {
      rep(j,10) f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    }
  }
  int ans = 0;
  rep(i,h) {
    rep(j,w) {
      int x;
      cin >> x;
      if(x==-1) continue;
      ans += f[x][1];
    }
  }
  cout << ans << endl;
  return 0;
}
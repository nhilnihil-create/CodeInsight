#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

int main() {
  int n;
  cin >> n;
  int f[n][10];
  rep(i,n) rep(j,10) cin >> f[i][j];

  vector<vector<ll>> p(n, vector<ll>(10));
  rep(i,n) rep(j,11) cin >> p[i][j];

  ll ans = -1 * M;
  rep(b, (1 << 10) - 1){
    ll x = 0;
    rep(i, n) {
      int c = 0;
      rep(k, 10) if (((b+1) >> k) & 1 && f[i][k]) c++;
      x += p[i][c];
    }
    ans = max(ans,x);
  }

  cout << ans << endl;
  return 0;
}

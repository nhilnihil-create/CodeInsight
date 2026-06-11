#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int r, g, b, n; cin >> r >> g >> b >> n;
  ll ans = 0;
  rep(i,n/r+1) {
    rep(j,n/g+1) {
      int sum = i*r + j*g;
      if (sum <= n && (n - sum) % b == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
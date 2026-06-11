#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll k, a, b; cin >> k >> a >> b;
  ll d = b-a;
  ll ans = 1;
  if (d <= 2) ans += k;
  else {
    rep(i,k) {
      if (i <= k - 2 && ans >= a && d > 2) {
        ans += d;
        i++;
      } else {
        ans++;
      }
      //cout << i << ":" << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
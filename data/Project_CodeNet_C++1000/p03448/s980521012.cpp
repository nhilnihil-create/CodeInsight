#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i <= n; ++i)

void solve(void){
  ll a, b, c, x; cin >> a >> b >> c >> x;

  ll res = 0;
  rep(a, i) {
    rep(b, j) {
      rep(c, k) {
        ll tmp = 500 * i + 100 * j + 50 * k;
        if (a + b + c >= 1 && tmp == x) ++res;
      }
    }
  }
  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}
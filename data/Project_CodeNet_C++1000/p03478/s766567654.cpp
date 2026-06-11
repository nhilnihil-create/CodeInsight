#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 1; i <= n; ++i)

void solve(void){
  ll n, a, b; cin >> n >> a >> b;

  ll res = 0;
  rep(n, i) {
    ll tmp = i;
    ll cnt = 0;

    while (tmp != 0) {
      cnt += tmp % 10;
      tmp /= 10;
    }

    if (a <= cnt && cnt <= b) res += i;
  }
  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}
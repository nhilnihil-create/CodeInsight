#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;

  ll bottleneck = min(a, min(b, min(c, min(d, e))));
  ll res = (n % bottleneck == 0) ? n / bottleneck : n / bottleneck + 1;

  cout << res + 4 << endl;
}

int main(void) {
  solve();
  return 0;
}
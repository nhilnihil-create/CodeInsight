#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void) {
  ll n; cin >> n;
  map<ll, ll> a;
  rep(n, i) {
    ll ta; cin >> ta;
    ++a[ta];
  }

  ll res = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    ll temp = iter->first - iter->second;
    if (temp > 0) res += iter->second;
    else res -= temp;
  }

  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}
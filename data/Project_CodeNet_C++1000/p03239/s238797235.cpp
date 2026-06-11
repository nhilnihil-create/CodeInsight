#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, t; cin >> n >> t;
  ll res = INF;
  rep(i, n) {
    ll c, tmp; cin >> c >> tmp;
    if (tmp <= t) res = min(res, c);
  }
  if (res == INF) cout << "TLE" << endl;
  else cout << res << endl;
}
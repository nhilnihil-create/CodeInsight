#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, m, c; cin >> n >> m >> c;
  vector <ll> b(m);
  rep(i, m) cin >> b.at(i);
  ll res = 0;
  rep(i, n) {
    ll tmp = c;
    rep(j, m) {
      ll a; cin >> a;
      tmp += a*b.at(j);
    }
    if (tmp > 0) res++;
  }
  cout << res << endl;
}
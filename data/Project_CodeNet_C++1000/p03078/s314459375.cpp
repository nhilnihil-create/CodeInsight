#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ll x, y, z; cin >> x >> y >> z;
  ll k; cin >> k;
  vector <ll> a(x), b(y), c(z);
  rep(i, x) cin >> a.at(i);
  rep(i, y) cin >> b.at(i);
  rep(i, z) cin >> c.at(i);
  vector <ll> ab;
  rep(i, x) {
    rep(j, y) {
      ab.push_back(a.at(i)+b.at(j));
    }
  }
  sort(ab.begin(), ab.end());
  reverse(ab.begin(), ab.end());
  sort(c.begin(), c.end());
  vector <ll> loc(z, 0);
  rep(i, k) {
    vector <pair <ll, ll>> v(z, pair <ll, ll> ());
    ll res = 0, max_loc;
    rep(j, z) {
      if (loc.at(j) < x*y) {
        ll tmp = c.at(j) + ab.at(loc.at(j));
        if (tmp > res) {
          res = tmp;
          max_loc = j;
        }
      }
    }
    cout << res << endl;
    loc.at(max_loc)++;
  }
}
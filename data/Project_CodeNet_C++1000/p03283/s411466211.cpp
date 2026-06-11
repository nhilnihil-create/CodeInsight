#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, m, q; cin >> n >> m >> q;
  vector <vector <ll>> v(n, vector <ll> ());
  rep(i, m) {
    ll l, r; cin >> l >> r;
    v.at(l-1).push_back(r-l);
  }
  rep(i, n) sort(v.at(i).begin(), v.at(i).end());
  rep(i, q) {
    ll l, r; cin >> l >> r;
    l--; r--;
    ll res = 0, dis = r - l;
    for (ll j = l; j <= r; j++) {
      auto itr = upper_bound(v.at(j).begin(), v.at(j).end(), dis);
      res += distance(v.at(j).begin(), itr);
      dis--;
    }
    cout << res << endl;
  }
}
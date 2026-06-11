#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, m; cin >> n >> m;
  vector <pair <ll, ll>> v(n, pair <ll, ll> ());
  rep(i, n) {
    ll a, b; cin >> a >> b;
    v.at(i) = make_pair(a, b);
  }
  sort(v.begin(), v.end());
  ll res = 0;
  rep(i, n) {
    if (v.at(i).second >= m) {
      res += v.at(i).first * m;
      break;
    } else {
      res += v.at(i).first * v.at(i).second;
      m -= v.at(i).second;
    }
  }
  cout << res << endl;
}
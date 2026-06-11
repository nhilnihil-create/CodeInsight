#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll h, w, d; cin >> h >> w >> d;
  vector <pair <ll, ll>> v(h*w, pair <ll, ll> ());
  rep(i, h) {
    rep(j, w) {
      ll a; cin >> a;
      v.at(a-1) = make_pair(i, j);
    }
  }
  vector <ll> imos(h*w, 0);
  rep(i, d) {
    ll tmp = i;
    while (tmp+d < h*w) {
      imos.at(tmp+d) = imos.at(tmp)+abs(v.at(tmp+d).first-v.at(tmp).first)+abs(v.at(tmp+d).second-v.at(tmp).second);
      tmp += d;
    }
  }
  ll q; cin >> q;
  rep(i, q) {
    ll l, r; cin >> l >> r;
    l--; r--;
    cout << imos.at(r) - imos.at(l) << endl;
  }
}
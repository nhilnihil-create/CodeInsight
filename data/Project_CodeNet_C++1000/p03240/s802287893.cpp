#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  vector <ll> x(n), y(n);
  vector <pair <ll, ll>> h(n, pair <ll, ll> ());
  rep(i, n) {
    cin >> x.at(i) >> y.at(i) >> h.at(i).first;
    h.at(i).second = i;
  }
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  rep(i, 101) {
    rep(j, 101) {
      bool flag = 1;
      ll res_h;
      rep(k, n) {
        ll loc = h.at(k).second;
        if (k) {
          if (h.at(k).first) {
            if (res_h != h.at(k).first+abs(i-x.at(loc))+abs(j-y.at(loc))) flag = 0;
          } else {
            if (res_h-abs(i-x.at(loc))-abs(j-y.at(loc)) > 0) flag = 0;
          }
        } else {
          res_h = h.at(k).first+abs(i-x.at(loc))+abs(j-y.at(loc));
        }
      }
      if (flag) {
        cout << i << ' ' << j << ' ' << res_h << endl;
        break;
      }
    }
  }
}
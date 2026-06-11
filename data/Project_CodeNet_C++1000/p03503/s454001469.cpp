#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <vector <ll>> f(n, vector <ll> (10));
  rep(i, n) {
    rep(j, 10) {
      cin >> f.at(i).at(j);
    }
  }
  vector <vector <ll>> p(n, vector <ll> (11));
  rep(i, n) {
    rep(j, 11) {
      cin >> p.at(i).at(j);
    }
  }
  ll res = -INF;
  for (int tmp = 0; tmp < (1 << 10); tmp++) {
    bitset <10> s(tmp);
    vector <ll> c(n, 0);
    bool flag = 1;
    rep(i, 10) {
      if (s.test(i)) {
        flag = 0;
        rep(j, n) {
          if (f.at(j).at(i)) c.at(j)++;
        }
      }
    }
    if (flag) continue;
    ll profit = 0;
    rep(i, n) {
      profit += p.at(i).at(c.at(i));
    }
    res = max(res, profit);
  }
  cout << res << endl;
}
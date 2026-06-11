#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  vector <ll> c(n-1), s(n-1), f(n-1);
  rep(i, n-1) cin >> c.at(i) >> s.at(i) >> f.at(i);
  rep(i, n) {
    ll res = 0;
    for (ll j = i; j < n-1; j++) {
      if (res <= s.at(j)) res = s.at(j) + c.at(j);
      else if ((res-s.at(j))%f.at(j) == 0) res += c.at(j);
      else res = s.at(j) + ((res-s.at(j))/f.at(j)+1)*f.at(j) + c.at(j);
    }
    cout << res << endl;
  }
}
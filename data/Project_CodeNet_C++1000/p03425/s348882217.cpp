#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  vector <ll> v(5, 0);
  rep(i, n) {
    string s; cin >> s;
    if (s.at(0) == 'M') v.at(0)++;
    else if (s.at(0) == 'A') v.at(1)++;
    else if (s.at(0) == 'R') v.at(2)++;
    else if (s.at(0) == 'C') v.at(3)++;
    else if (s.at(0) == 'H') v.at(4)++;
  }
  ll res = 0;
  for (ll bit = 0; bit < (1 << 5); bit++) {
    if (__builtin_popcount(bit) != 3) continue;
    ll tmp = 1;
    rep(i, 5) {
      if (bit&(1<<i)) tmp *= v.at(i);
    }
    res += tmp;
  }
  cout << res << endl;
}
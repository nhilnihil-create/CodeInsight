#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <ll> v(n), u(n);
  rep(i, n) cin >> v.at(i);
  rep(i, n) cin >> u.at(i);
  ll res = 0;
  rep(i, n) {
    if (v.at(i) > u.at(i)) res += v.at(i)-u.at(i);
  }
  cout << res << endl;
}
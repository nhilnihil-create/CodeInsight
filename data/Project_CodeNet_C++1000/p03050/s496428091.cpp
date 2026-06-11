#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;

  vector<ll> div;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      div.push_back(i);
      if (i != n / i) div.push_back(n / i);
    }
  }

  ll ans = 0;
  for (auto x : div) {
    ll m = n / x - 1;
    if (m == 0) continue;
    if (n / m == n % m) ans += m;
  }
  cout << ans << endl;
  return 0;
}

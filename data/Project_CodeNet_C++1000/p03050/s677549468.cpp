#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n;
  cin >> n;
  vector <ll> div;
  for (ll d = 1; d * d <= n; d++) {
    if (n % d == 0) {
      if (d != 1) div.push_back(d);
      if (d != n / d) div.push_back(n / d);
    }
  }
  ll ans = 0;
  for (ll d: div) {
    ll m = d - 1;
    if (n % m == n / m) {
      ans += m;
    }
  }
  cout << ans << endl;
  return (0);
}
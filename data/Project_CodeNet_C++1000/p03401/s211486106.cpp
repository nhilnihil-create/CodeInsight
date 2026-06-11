#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  a.emplace(a.begin(), 0);
  a.emplace_back(0);
  ll ans = 0;
  for (ll i = 1; i < (ll)a.size(); i++) ans += abs(a[i] - a[i - 1]);
  for (ll i = 1; i <= n; i++) {
    cout << ans - (abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1])) +
                abs(a[i + 1] - a[i - 1])
         << endl;
  }
  return 0;
}

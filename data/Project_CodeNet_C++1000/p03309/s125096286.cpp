#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), aa(n);
  unordered_map<ll, ll> mp;
  rep(i, n) cin >> a[i], a[i] -= i + 1;
  sort(a.begin(), a.end());
  ll b = a[n / 2];

  ll ans = 0;
  for (int i = 0; i < n; ++i) ans += abs(a[i] - b);

  cout << ans << endl;
  return 0;
}

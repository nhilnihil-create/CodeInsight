#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), ab;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0, s = 0;
  rep(i, n) {
    if (a[i] < b[i]) {
      ans++;
      s += b[i] - a[i];
    } else {
      ab.push_back(a[i] - b[i]);
    }
  }
  sort(ab.rbegin(), ab.rend());

  rep(i, ab.size()) {
    if (s <= 0) break;
    s -= ab[i];
    ans++;
  }

  if (s > 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}

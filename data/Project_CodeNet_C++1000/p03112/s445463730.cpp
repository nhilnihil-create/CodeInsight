#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
  ll a, b, q, x, ans;
  cin >> a >> b >> q;
  vector<ll> s(a + 2), t(b + 2);
  rep(i, a) cin >> s[i + 1];
  rep(i, b) cin >> t[i + 1];
  s[0] = t[0] = -INF;
  s[a + 1] = t[b + 1] = INF;

  rep(i, q) {
    cin >> x;
    ans = INF;
    ll si = upper_bound(s.begin(), s.end(), x) - s.begin();
    ll ti = upper_bound(t.begin(), t.end(), x) - t.begin();

    for (int i = si - 1; i <= si; ++i) {
      for (int j = ti - 1; j <= ti; ++j) {
        ll mn1 = abs(s[i] - x) + abs(t[j] - s[i]);
        ll mn2 = abs(s[i] - t[j]) + abs(t[j] - x);
        ans = min({ans, mn1, mn2});
      }
    }
    cout << ans << endl;
  }

  return 0;
}
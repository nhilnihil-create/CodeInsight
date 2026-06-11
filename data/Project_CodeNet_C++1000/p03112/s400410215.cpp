#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b, q;
  cin >> a >> b >> q;

  vector<ll> s(a);
  rep(i, a) cin >> s[i];
  vector<ll> t(b);
  rep(i, b) cin >> t[i];
  vector<ll> x(q);
  rep(i, q) cin >> x[i];

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  rep(i, q) {
    ll ans = 2 * 10'000'000'000;
    int slb = lower_bound(s.begin(), s.end(), x[i]) - s.begin();
    int tlb = lower_bound(t.begin(), t.end(), x[i]) - t.begin();

    if (slb < a && tlb < b) ans = min(ans, max(s[slb], t[tlb]) - x[i]);
    if (slb > 0 && tlb > 0) ans = min(ans, x[i] - min(s[slb - 1], t[tlb - 1]));
    if (slb < a && tlb > 0) {
      ll d1 = s[slb] - x[i];
      ll d2 = x[i] - t[tlb - 1];
      ans = min(ans, d1 + d2 + min(d1, d2));
    }
    if (slb > 0 && tlb < b) {
      ll d1 = x[i] - s[slb - 1];
      ll d2 = t[tlb] - x[i];
      ans = min(ans, d1 + d2 + min(d1, d2));
    }

    cout << ans << endl;
  }
  return 0;
}
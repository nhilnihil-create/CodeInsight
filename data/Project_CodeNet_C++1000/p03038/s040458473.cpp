#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), aa;
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<P> p;
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    p.emplace_back(c, b);
  }
  sort(p.rbegin(), p.rend());
  for (auto x : p) {
    rep(i, x.second) aa.push_back(x.first);
    if (n <= aa.size()) break;
  }
  // rep(i, n) fprintf(stderr, "%d%c", a[i], (i == n - 1 ? '\n' : ' '));
  // rep(i, n) fprintf(stderr, "%d%c", aa[i], (i == n - 1 ? '\n' : ' '));

  ll ans = 0;
  rep(i, n) {
    if (aa.size() <= i) {
      ans += a[i];
    } else {
      ans += max(a[i], aa[i]);
    }
  }
  cout << ans << endl;
  return 0;
}

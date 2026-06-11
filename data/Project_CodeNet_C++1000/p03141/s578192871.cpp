#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<P> c(n);
  rep(i, n) c[i] = make_pair(-a[i]-b[i], i);
  sort(c.begin(), c.end());
  ll ans = 0;
  rep(i, n) {
    if (i % 2 == 0) ans += a[c[i].second];
    else ans -= b[c[i].second];
  }
  cout << ans << endl;
  return 0;
}
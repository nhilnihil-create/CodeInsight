#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  ll ans=0;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  rep (i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  
  rep (i, n) {
    if (lower_bound(a.begin(), a.end(), b[i]) != a.begin()) {
      ll x = (lower_bound(a.begin(), a.end(), b[i]) - a.begin());
      ll y = (c.end() - upper_bound(c.begin(), c.end(), b[i]));
      ans += x * y;
    }
  }

  cout << ans << endl;
}
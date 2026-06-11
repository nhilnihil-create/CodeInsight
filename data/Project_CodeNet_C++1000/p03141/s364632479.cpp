#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll b_sum = 0;
  rep(i, n) {
    c[i] = a[i] + b[i];
    b_sum += b[i];
  }
  sort(c.rbegin(), c.rend());

  ll ans = 0;
  for (int i = 0; i < n; i += 2) ans += c[i];
  ans -= b_sum;

  cout << ans << endl;

  return 0;
}

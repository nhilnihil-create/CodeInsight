#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> l(n + 1), r(n + 1);
  for (int i = 0; i < n; i++) l[i + 1] = gcd(l[i], a[i]);
  for (int i = n - 1; i >= 0; i--) r[i] = gcd(r[i + 1], a[i]);

  ll ans = 0;
  rep(i, n) {
    ll g = gcd(l[i], r[i + 1]);
    ans = max(ans, g);
  }
  cout << ans << endl;
  return 0;
}

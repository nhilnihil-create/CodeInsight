#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;

ll gcd(ll a, ll b) {
  if (a == INF) return b;
  if (b == INF) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];

  ll l[n + 1], r[n + 1];
  l[0] = r[0] = INF;
  rep(i, n) {
    l[i + 1] = gcd(l[i], a[i]);
    r[i + 1] = gcd(r[i], a[n - 1 - i]);
  }

  ll ans = 1;
  rep(i, n) ans = max(ans, gcd(l[i], r[n - i - 1]));
  cout << ans << endl;

  return 0;
}

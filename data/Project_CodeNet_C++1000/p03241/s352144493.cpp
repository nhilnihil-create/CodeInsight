#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  ll ans = 1;

  for (ll a = 1; a * a <= m; a++) {
    if (m % a)
      continue;
    ll b = m / a;
    if (a * n <= m)
      chmax(ans, a);
    if (b * n <= m)
      chmax(ans, b);
  }
  cout << ans << endl;
}

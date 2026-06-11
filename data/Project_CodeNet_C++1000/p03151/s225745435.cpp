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

  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];

  vector<ll> diff(n);
  ll minv = 0;
  int ans = 0;
  rep(i, 0, n) {
    diff[i] = a[i] - b[i];
    if (diff[i] < 0) {
      minv += diff[i];
      ans++;
    }
  }

  sort(diff.rbegin(), diff.rend());
  if (minv < 0) {
    rep(i, 0, n) {
      minv += diff[i];
      ans++;
      if (minv >= 0)
        break;
    }
  }

  if (minv < 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

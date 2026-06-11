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
  vector<int> x(m);
  rep(i, 0, m) cin >> x[i];
  sort(x.begin(), x.end());

  vector<int> absdiff(m - 1);
  rep(i, 1, m) absdiff[i - 1] = abs(x[i] - x[i - 1]);

  sort(absdiff.rbegin(), absdiff.rend());
  ll ans = 0;
  rep(i, n - 1, m - 1) ans += absdiff[i];

  cout << ans << endl;
}

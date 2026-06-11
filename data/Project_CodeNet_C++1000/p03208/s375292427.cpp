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

  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  sort(h.begin(), h.end());

  int ans = 1e9 + 7;
  k--;
  rep(i, k, n) { chmin(ans, h[i] - h[i - k]); }

  cout << ans << endl;
}

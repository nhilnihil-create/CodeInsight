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
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];

  int maxv = h[0];
  ll ans = 0;
  rep(i, 1, n) {
    if (h[i] < h[i - 1]) {
      ans += maxv - h[i];
      maxv = 0;
    }
    chmax(maxv, h[i]);
  }

  if (maxv)
    ans += maxv;
  cout << ans << endl;
}

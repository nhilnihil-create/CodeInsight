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

  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(a.begin(), a.end());

  int ans = 0;
  rep(i, 0, n) {
    x -= a[i];
    if (x < 0)
      break;
    if (i == n - 1 && x != 0)
      break;
    ans++;
  }

  cout << ans << endl;
}

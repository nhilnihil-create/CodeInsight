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
  vector<int> v(n);

  rep(i, 0, n) cin >> v[i];

  int ans = abs(v[0]- x);
  rep(i, 1, n) {
    ans = __gcd(ans, abs(v[i] - v[i-1]));
  }

  cout << ans << endl;
}

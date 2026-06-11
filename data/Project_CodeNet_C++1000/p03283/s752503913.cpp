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

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> v(501, vector<int>(501, 0));
  vector<vector<int>> acc = v;
  rep(i, 0, m) {
    int l, r;
    cin >> l >> r;
    v[l][r]++;
  }

  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) { acc[i][j] = acc[i][j - 1] + v[i][j]; }
  }

  while (q--) {
    int p, q;
    cin >> p >> q;
    int ans = 0;
    rep(i, p, q + 1) ans += acc[i][q] - acc[i][p - 1];
    cout << ans << endl;
  }

  cout << endl;
}

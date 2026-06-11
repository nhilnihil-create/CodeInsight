#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n, a, b, c;
vector<int> l;

int dfs(int m, int aa, int bb, int cc, int t) {
  if (m == n) {
    if (aa == 0 || bb == 0 || cc == 0)
      return 1e9;
    return t + abs(a - aa) + abs(b - bb) + abs(c - cc) - 30;
  }
  int m1 = dfs(m + 1, aa + l[m], bb, cc, t + 10);
  int m2 = dfs(m + 1, aa, bb + l[m], cc, t + 10);
  int m3 = dfs(m + 1, aa, bb, cc + l[m], t + 10);
  int m4 = dfs(m + 1, aa, bb, cc, t);
  return min({m1, m2, m3, m4});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i, 0, n) cin >> l[i];
  int ans = dfs(0, 0, 0, 0, 0);
  cout << ans << endl;
}

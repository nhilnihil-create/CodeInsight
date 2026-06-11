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

  int n, m, Q;
  cin >> n >> m >> Q;
  vector<int> l(m), r(m);
  vector<vector<int>> x(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> c = x;

  rep(i, 0, m) {
    cin >> l[i] >> r[i];
    x[l[i]][r[i]]++;
  }

  rep(i, 1, n + 1) { rep(j, 1, n + 1) c[i][j] = c[i][j - 1] + x[i][j]; }

  rep(i, 1, Q + 1) {
    int p, q;
    cin >> p >> q;
    int sumv = 0;
    rep(j, p, q + 1) sumv += c[j][q] - c[j][p - 1];
    cout << sumv << endl;
  }
}

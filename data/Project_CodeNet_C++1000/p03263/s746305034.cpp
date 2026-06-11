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

  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];

  vector<tuple<int, int, int, int>> v;
  rep(i, 0, h) rep(j, 0, w) {
    if (a[i][j] & 1) {
      if (j < w - 1) {
        a[i][j + 1]++;
        a[i][j]--;
        v.emplace_back(i + 1, j + 1, i + 1, j + 2);
      } else {
        if (i < h - 1) {
          a[i + 1][j]++;
          a[i][j]--;
          v.emplace_back(i + 1, j + 1, i + 2, j + 1);
        }
      }
    }
  }

  cout << v.size() << endl;
  for (auto vv : v) {
    cout << get<0>(vv) << " " << get<1>(vv) << " " << get<2>(vv) << " "
         << get<3>(vv) << endl;
  }
}

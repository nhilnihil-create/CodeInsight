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
  vector<vector<int>> v(n, vector<int>(3));
  int not_zero = -1;
  rep(i, 0, n) {
    rep(j, 0, 3) cin >> v[i][j];
    if (v[i][2])
      not_zero = i;
  }

  rep(cx, 0, 101) {
    rep(cy, 0, 101) {
      bool flg = true;
      ll H =
          abs(v[not_zero][0] - cx) + abs(v[not_zero][1] - cy) + v[not_zero][2];
      rep(i, 0, n) {
        ll h = abs(v[i][0] - cx) + abs(v[i][1] - cy);
        if ((v[i][2] == 0 && H > h) || (v[i][2] > 0 && H - v[i][2] != h))
          flg = false;
      }
      if (flg) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
}

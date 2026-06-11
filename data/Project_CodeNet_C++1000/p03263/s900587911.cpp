#include <bits/stdc++.h>

using namespace std;

template <typename T> void debug(T v) { cout << v << endl; } /* {{{ */
template <typename T, typename... Rest> void debug(T v, Rest... r) {
  cout << v << " ";
  debug(r...);
}
template <typename T> void debug(const vector<T> &v) {
  for (const auto &e : v) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T> void debug(const vector<vector<T>> &vv) {
  for (const auto &v : vv) {
    debug(v);
  }
} /* }}} */

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  int i = 0, j = 0;
  int carry = 0;
  vector<vector<int>> ans;
  while (true) {
    A[i][j] += carry;

    int ni = i, nj = j;
    if (i % 2 == 0) {
      if (j == W - 1) {
        if (i == H - 1) break;
        ni++;
      } else {
        nj++;
      }
    } else {
      if (j == 0) {
        if (i == H - 1) break;
        ni++;
      } else {
        nj--;
      }
    }

    if (A[i][j] % 2) {
      ans.push_back({i, j, ni, nj});
      carry = 1;
    } else {
      carry = 0;
    }
    i = ni;
    j = nj;
  }
  cout << ans.size() << endl;
  for (auto a : ans) {
    for (int i = 0; i < 4; i++) {
      if (i > 0) cout << " ";
      cout << a[i] + 1;
    }
    cout << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */

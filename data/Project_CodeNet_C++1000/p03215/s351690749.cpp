#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Returns a vector of cumulative sums.
// Let c_sums be the return value.
// - c_sums[k] is the sum of xs over [0, k).
// - c_sums[r] - c_sums[l] is the sum of xs over [l, r).
template<class T> vector<T> CumulativeSumVector(const vector<T>& xs) {
  int n = xs.size(); vector<T> c_sums(n + 1);
  for (int i = 0; i < n; i++) c_sums[i + 1] = c_sums[i] + xs[i];
  return c_sums;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int k;
  cin >> n >> k;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto cumulative_xs = CumulativeSumVector(xs);
  vector<int64> ys;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      ys.push_back(cumulative_xs[i] - cumulative_xs[j]);
    }
  }

  int64 ans = 0;
  for (int b = 59; b >= 0; b--) {
    int64 z = 1LL << b;
    int c = 0;
    for (int64 y : ys) {
      if (y & z) {
        c++;
      }
    }
    if (c >= k) {
      ans |= z;
      vector<int64> next_ys;
      for (int64 y : ys) {
        if (y & z) {
          next_ys.push_back(y);
        }
      }
      ys = next_ys;
    }
  }
  cout << ans << endl;
}
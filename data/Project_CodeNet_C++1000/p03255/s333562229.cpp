#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

// 累積和　1-indexed
template <typename T> class CumulativeSum {
  std::vector<T> _sums;

public:
  CumulativeSum(const vector<T> &v) : _sums(v) {
    _sums.insert(_sums.begin(), 0);
    for (int i = 1; i < (int)_sums.size(); ++i) {
      _sums[i] += _sums[i - 1];
    }
  }

  // sum of [1, index]
  T sum(int index) { return _sums[index]; }

  // sum of [left, right]
  T sum(int left, int right) { return sum(right) - sum(left - 1); }
};

int main() {
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> x(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
  }
  CumulativeSum<ll> sums(x);
  ll ans = 1e18;
  for (int i = 1; i <= N; ++i) {
    ll ret = (N + i) * X + 2 * sums.sum(N - i + 1, N);
    auto n = N;
    for (int p = 3;; p += 2) {
      ret += p * sums.sum(max(1, n - i + 1), n);
      n -= i;
      if (n < 1)
        break;
    }
    ans = min(ans, ret);
  }
  cout << ans << endl;
}

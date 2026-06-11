/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t f(const int32_t n) {
  return (n % 2 == 0) ? n / 2 : 3 * n + 1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N, x;
  cin >> N >> x;
  vector<int32_t> A(N);
  for (int32_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int32_t count = 0;
  for (int32_t i = 0; i < N; ++i) {
    if (x - A[i] >= 0) {
      ++count;
      x -= A[i];
    } else {
      x = 0;
      break;
    }
  }
  if (x > 0) {
    count = max(0, count - 1);
  }
  cout << count << endl;

  return 0;
}

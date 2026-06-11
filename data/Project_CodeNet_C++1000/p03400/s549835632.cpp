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

  int32_t N, D, X;
  cin >> N >> D >> X;
  vector<int32_t> A(N);
  int32_t count = 0;
  for (int32_t i = 0; i < N; ++i) {
    cin >> A[i];
    count += (D - 1)/A[i] + 1;
  }
  const int32_t num = count + X;
  cout << num << endl;

  return 0;
}

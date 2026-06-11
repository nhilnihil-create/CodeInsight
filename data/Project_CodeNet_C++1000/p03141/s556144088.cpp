/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  vector<Pair> C(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    C[i].first = A[i] + B[i];
    C[i].second = i;
  }
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  int64_t result = 0;
  int64_t takahashi = 1;
  for (int64_t i = 0; i < N; ++i) {
    if (takahashi) {
      result += A[C[i].second];
    } else {
      result -= B[C[i].second];
    }
    takahashi = 1 - takahashi;
  }
  cout << result << endl;
  return 0;
}

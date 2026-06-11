/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  vector<Pair> A;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    A.emplace_back(Pair(a, 1));
  }
  for (int64_t j = 0; j < M; ++j) {
    int64_t b, c;
    cin >> b >> c;
    A.emplace_back(Pair(c, b));
  }
  sort(A.begin(), A.end(), std::greater<Pair>());

  int64_t result = 0;
  for (int64_t i = 0; i < static_cast<int64_t>(A.size()); ++i) {
    const int64_t card = A[i].first;
    const int64_t count = A[i].second;
    const int64_t counted = min(N, count);
    result += card * counted;
    N -= counted;
    if (N <= 0) {
      break;
    }
  }
  cout << result << endl;
  return 0;
}

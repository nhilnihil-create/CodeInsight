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
  int64_t result = 0;
  for (int64_t divison = 1; divison * divison <= N; ++divison) {
    const int64_t m_1 = divison - 1;
    if (m_1 > 0 && (N / m_1) == (N % m_1)) {
      result += m_1;
    }
    const int64_t m_2 = N / divison - 1;
    if (m_2 > 0 && (N / m_2) == (N % m_2)) {
      result += m_2;
    }
  }
  cout << result << endl;
  return 0;
}

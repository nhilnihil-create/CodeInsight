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

  int64_t N, K;
  string S;
  cin >> N >> K >> S;
  vector<int64_t> A(N);
  vector<int64_t> counts;
  int64_t count = 0;
  int64_t pval = 1;
  for (int64_t i = 0; i < N; ++i) {
    const int64_t cval = static_cast<int64_t>(S[i] - '0');
    if (cval == pval) {
      ++count;
    } else {
      counts.emplace_back(count);
      // cerr << " " << count << endl;
      count = 1;
      pval = cval;
    }
  }
  if (count > 0) {
    counts.emplace_back(count);
  }
  if (S[N - 1] == '0') {
    counts.emplace_back(0);
  }
  int64_t result = 0;
  int64_t sum = 0;
  int64_t right = 0;
  for (int64_t left = 0; left < static_cast<int64_t>(counts.size()); left += 2) {
    // cerr << " " << counts[left] << endl;
    while (right <= min(left + K * 2, static_cast<int64_t>(counts.size()) - 1)) {
      // cerr << "aa " << right << endl;
      sum += counts[right];
      ++right;
    }
    // cerr << "  " << sum << endl;
    result = max(result, sum);
    // cerr << " " << counts[left] << " " << counts[left + 1] << endl;
    sum -= counts[left];
    sum -= counts[left + 1];
  }
  cout << result << endl;
  return 0;
}

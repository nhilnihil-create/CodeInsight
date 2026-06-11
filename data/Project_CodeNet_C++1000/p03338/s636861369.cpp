/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N;
  string S;
  cin >> N >> S;

  int32_t result = 0;
  for (int32_t start = 1; start < N; ++start) {
    vector<bool> S1_match(256, false);
    vector<bool> both_match(256, false);
    for (int32_t i = 0; i < start; ++i) {
      S1_match[S.c_str()[i]] = true;
    }
    for (int32_t i = start; i < N; ++i) {
      if (S1_match[S.c_str()[i]]) {
        both_match[S.c_str()[i]] = true;
      }
    }
    int32_t count = 0;
    for (int32_t i = 0; i < 256; ++i) {
      if (both_match[i]) {
        ++count;
      }
    }
    result = max(result, count);
  }
  cout << result << endl;

  return 0;
}

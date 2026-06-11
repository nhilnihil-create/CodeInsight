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

  string S;
  cin >> S;
  const int64_t L = static_cast<int64_t>(S.length());
  int64_t begin = 0;
  int64_t end = L - 1;
  int64_t result = 0;
  while (begin < end) {
    if (S.c_str()[begin] == S.c_str()[end]) {
      ++begin;
      --end;
    } else if (S.c_str()[begin] == 'x') {
      ++begin;
      ++result;
    } else if (S.c_str()[end] == 'x') {
      --end;
      ++result;
    } else {
      result = -1;
      break;
    }
  }
  cout << result << endl;
  return 0;
}

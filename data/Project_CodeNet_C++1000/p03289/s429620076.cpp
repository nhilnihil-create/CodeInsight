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

  string S;
  cin >> S;
  const int32_t length = static_cast<int32_t>(S.length());
  int32_t count_c = 0;
  bool is_okay = true;
  for (int32_t i = 0; i < length; ++i) {
    const char ch = S.c_str()[i];
    if (i == 0) {
      if (ch != 'A') {
        is_okay = false;
        break;
      }
    } else if (i >= 2 && i <= length - 2 && ch == 'C') {
      ++count_c;
      if (count_c > 1) {
        is_okay = false;
        break;
      }
    } else {
      if (ch < 'a' || ch > 'z') {
        is_okay = false;
        break;
      }
    }
  }
  if (count_c != 1) {
    is_okay = false;
  }
  if (is_okay) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
  return 0;
}

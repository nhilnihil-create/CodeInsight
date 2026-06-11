/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t neighbours[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  const int32_t length = static_cast<int32_t>(S.length());
  bool is_okay = false;
  if (S == "keyence") {
    is_okay = true;
  } else {
    for (int32_t start = 0; start < length; ++start) {
      for (int32_t sub_length = 1; start + sub_length <= length; ++sub_length) {
        const string modified_s = S.substr(0, start) + S.substr(start + sub_length, length);
        if (modified_s == "keyence") {
          is_okay = true;
          break;
        }
      }
      if (is_okay) {
        break;
      }
    }
  }
  if (is_okay) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

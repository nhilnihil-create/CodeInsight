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

  int32_t A, B;
  string S;
  cin >> A >> B >> S;
  const int32_t length = static_cast<int32_t>(S.length());

  bool is_okay = true;
  if (S.c_str()[A] != '-') {
    is_okay = false;
  }
  for (int32_t i = 0; i < A; ++i) {
    if (S.c_str()[i] >= '0' && S.c_str()[i] <= '9') {
      // do nothing
    } else {
      is_okay = false;
    }
  }
  for (int32_t i = A + 1; i < length; ++i) {
    if (S.c_str()[i] >= '0' && S.c_str()[i] <= '9') {
      // do nothing
    } else {
      is_okay = false;
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

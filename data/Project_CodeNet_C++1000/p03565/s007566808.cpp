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

  string S, T, result;
  cin >> S >> T;
  const int64_t SL = static_cast<int64_t>(S.length());
  const int64_t TL = static_cast<int64_t>(T.length());

  auto Match = [&](const int64_t start) -> bool {
    if (start + TL > SL) {
      return false;
    }
    for (int64_t i = 0; i < TL; ++i) {
      if (S[start + i] != '?' && S[start + i] != T[i]) {
        return false;
      }
    }
    return true;
  };

  bool found = false;
  result = S;
  for (int64_t i = SL - 1; i >= 0; --i) {
    if (Match(i)) {
      for (int64_t j = 0; j < TL; ++j) {
        result[i + j] = T[j];
      }
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for (int64_t i = 0; i < SL; ++i) {
    if (result[i] == '?') {
      result[i] = 'a';
    }
  }
  cout << result << endl;
  return 0;
}

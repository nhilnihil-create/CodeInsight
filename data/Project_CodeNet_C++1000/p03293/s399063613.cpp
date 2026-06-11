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

  string S, T;
  cin >> S >> T;
  string temp = S;
  const int64_t L = static_cast<int64_t>(S.length());
  for (int64_t i = 0; i < L; ++i) {
    temp = temp.substr(L - 1, 1) + temp.substr(0, L - 1);
    if (temp == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

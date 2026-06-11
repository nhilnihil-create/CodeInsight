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

  int64_t K, A, B;
  cin >> K >> A >> B;
  if (B - A <= 2) {
    cout << (K + 1) << endl;
    return 0;
  }
  int64_t c_bis = 1;
  K -= (A - c_bis);
  c_bis = A;

  const int64_t count_2 = K / 2;
  c_bis += (B - A) * count_2;
  K -= count_2 * 2;
  if (K > 0) {
    c_bis += K;
  }
  cout << c_bis << endl;
  return 0;
}

/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int64_t Myxor(const int64_t x) {
  if (x < 0) {
    return 0;
  }
  int64_t result = 0;
  int64_t d = 0;
  while ((x >> d) > 0) {
    const int64_t L = (1L << d);
    if (d == 0 && (x % 4 == 1 || x % 4 == 2)) {
      result++;
    } else if ((x / L) % 2 == 1) {
      if ((x % 2) == 0) {
        result += (1LL << d);
        // cerr << "hoge " << d << ", " << (1L << d) << endl;
      }
    }
    d++;
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t A, B;
  cin >> A >> B;
  cout << (Myxor(B) ^ Myxor(A - 1)) << endl;
  return 0;
}

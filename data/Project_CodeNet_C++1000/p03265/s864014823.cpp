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

  int32_t x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  complex<int32_t> p1(x1, y1), p2(x2, y2);
  complex<int32_t> d12 = p2 - p1;
  const complex<int32_t> I(0, 1);
  const complex<int32_t> d14 = d12 * I;
  complex<int32_t> p4 = p1 + d14;
  complex<int32_t> p3 = p2 + d14;
  cout << p3.real() << " " << p3.imag() << " " << p4.real() << " " << p4.imag() << endl;
  return 0;
}

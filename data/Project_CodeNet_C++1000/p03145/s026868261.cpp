#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << A * B / 2  << endl;
  return 0;
}

#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll T, ll X) {
  auto ans = (ld)T/X;
  cout << fixed << ans << endl;
}

int main() {
  ll T;
  cin >> T;
  ll X;
  cin >> X;
  solve(T, X);
  return 0;
}

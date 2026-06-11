#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll R, ll G) {
  cout << 2*G-R << endl;
}

int main() {
  ll R;
  cin >> R;
  ll G;
  cin >> G;
  solve(R, G);
  return 0;
}

#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, ll B, ll T) {
  cout << T/A * B << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll T;
  cin >> T;
  solve(A, B, T);
  return 0;
}

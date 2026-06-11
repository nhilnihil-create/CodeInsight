#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll i) { cout << N - i + 1 << endl; }

int main() {
  ll N;
  cin >> N;
  ll i;
  cin >> i;
  solve(N, i);
  return 0;
}

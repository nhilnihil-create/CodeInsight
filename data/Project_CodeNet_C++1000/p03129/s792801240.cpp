#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(ll N, ll K) {
  bool pred = 2 * K - 1 <= N;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll K;
  cin >> K;
  solve(N, K);
  return 0;
}

#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll A, ll B) {
  cout << min(A*N,B) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(N, A, B);
  return 0;
}

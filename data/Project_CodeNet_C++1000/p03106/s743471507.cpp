#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, ll B, ll K) {
  int c{};
  for (auto i = min(A, B); i; --i) {
    if (A % i == 0 && B % i == 0) ++c;
    if (c == K) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll K;
  cin >> K;
  solve(A, B, K);
  return 0;
}

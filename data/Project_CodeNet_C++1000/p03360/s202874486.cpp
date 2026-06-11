#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
T power(T x, int n) {
  T ans{1};
  while (n) {
    if (n % 2) ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}

void solve(ll A, ll B, ll C, ll K) {
  ll ma = max({A,B,C});
  cout << A+B+C+(power(2,K)-1)*ma << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  ll K;
  cin >> K;
  solve(A, B, C, K);
  return 0;
}

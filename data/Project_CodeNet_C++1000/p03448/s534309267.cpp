#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, ll B, ll C, ll X) {
  int ans{};
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      for (int k = 0; k <= C; ++k) {
        if (500 * i + 100 * j + 50 * k == X) ++ans;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  ll X;
  cin >> X;
  solve(A, B, C, X);
  return 0;
}

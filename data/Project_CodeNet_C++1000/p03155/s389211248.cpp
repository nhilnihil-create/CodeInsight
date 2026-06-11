#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll H, ll W) {
  int ans = (N-H+1)*(N-W+1);
  cout << ans << endl;
}

int main() {
  ll N;
  cin >> N;
  ll H;
  cin >> H;
  ll W;
  cin >> W;
  solve(N, H, W);
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N) {
  auto s = to_string(N);
  int ans = count_if(ALL(s), [](char c) { return c == '2'; });
  cout << ans << endl;
}

int main() {
  ll N;
  cin >> N;
  solve(N);
  return 0;
}

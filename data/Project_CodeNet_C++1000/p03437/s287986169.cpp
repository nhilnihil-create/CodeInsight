#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll X, ll Y) {
  ll ans{};
  if(X%Y==0) {
    ans = -1;
  } else {
    ans = X;
  }
  
  cout << ans << endl;
}

int main() {
  ll X;
  cin >> X;
  ll Y;
  cin >> Y;
  solve(X, Y);
  return 0;
}

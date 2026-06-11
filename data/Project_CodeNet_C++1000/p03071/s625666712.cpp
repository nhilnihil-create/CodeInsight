#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;


#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, ll B) {
  int ans;
  if (A==B) {
    ans = A+B;
  } else {
    ans = 2*max(A,B) - 1;
  }
  cout << ans << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}

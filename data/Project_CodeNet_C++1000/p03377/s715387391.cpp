#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

void solve(ll A, ll B, ll X) {
  bool pred = A <= X && X <= A+B;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll X;
  cin >> X;
  solve(A, B, X);
  return 0;
}

#include <iostream>
#include <string>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yay!";
const string NO = ":(";

void solve(ll A, ll B) { cout << (A <= 8 && B <= 8 ? YES : NO) << endl; }

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}

#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(ll A, ll B, string S) {
  bool pred = all_of(begin(S), begin(S)+A, [](unsigned char c){return isdigit(c);}) && all_of(rbegin(S), rbegin(S)+B, [](unsigned char c){return isdigit(c);}) && S[A]=='-';

  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  string S;
  cin >> S;
  solve(A, B, S);
  return 0;
}

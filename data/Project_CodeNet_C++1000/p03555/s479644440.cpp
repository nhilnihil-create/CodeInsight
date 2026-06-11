#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "YES";
const string NO = "NO";

int main() {
  string c0,c1;
  cin >> c0 >> c1;
  cout << (c0[0] == c1[2] && c0[1] == c1[1] && c0[2] == c1[0] ? YES : NO) << endl;
  return 0;
}

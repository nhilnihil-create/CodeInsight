#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(string X, string Y) {
  cout << (X < Y ? "<" : X > Y ? ">" : "=") << endl;
}

int main() {
  string X;
  cin >> X;
  string Y;
  cin >> Y;
  solve(X, Y);
  return 0;
}

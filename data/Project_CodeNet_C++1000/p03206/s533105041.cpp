#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll D) {
  string str = "Christmas";
  while(D < 25) {
    str += " Eve";
    ++D;
  }
  cout << str << endl;
}

int main() {
  ll D;
  cin >> D;
  solve(D);
  return 0;
}

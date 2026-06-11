#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll R) {
  if (R < 1200){
    cout << "ABC" << endl;
  } else if (R < 2800) {
    cout << "ARC" << endl;
  } else {
    cout << "AGC" << endl;
  }
}

int main() {
  ll R;
  cin >> R;
  solve(R);
  return 0;
}

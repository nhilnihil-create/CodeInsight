#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  int r, D, x;
  cin >> r >> D >> x;

  for (auto y = 2000; y !=2010; ++y) {
    x = r*x-D;
    cout << x << endl;
  }
  
  return 0;
}

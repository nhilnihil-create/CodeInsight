#include <iostream>
using namespace std;

using int64 = long long;

int64 Solve(int64 n, int64 p) {
  int64 ret = 1;
  for (int64 a = 2; a * a <= p; ++a) {
    int e = 0;
    while (p % a == 0) {
      p /= a;
      ++e;
    }
    for (e /= n; e; e--)
      ret *= a;
  }
  if (n == 1)
    ret *= p;

  return ret;
}

int main() {
  int64 n, p;
  cin >> n >> p;
  cout << Solve(n, p) << "\n";
  return 0;
}

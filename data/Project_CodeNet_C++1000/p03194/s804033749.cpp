#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long N, P;
  cin >> N >> P;
  long long x = pow(P, 1.0 / N) + 1;
  while (x > 1) {
    long long temp = pow(x, N);
    if (P % temp == 0) {
      cout << x << endl;
      return 0;
    }
    --x;
  }
  cout << 1 << endl;
  return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int m = 0;

  if (A + B > 2 * C) {
    m = min(X, Y);
    X -= m;
    Y -= m;
    m *= 2;
  }
  if (X > 0 && A > 2 * C) {
    m += 2 * X;
    X = 0;
    Y = 0;
  }
  if (Y > 0 && B > 2 * C) {
    m += 2 * Y;
    X = 0;
    Y = 0;
  }

  cout << A * X + B * Y + C * m << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1;
  double x2, a, b;
  cin >> a >> b;
  x2 = (a + b) / 2;
  x1 = x2;
  x2 -= x1;
  if (x2 > 0) {
    cout << x1 + 1 << endl;
} else {
    cout << x1 << endl;
  }
}

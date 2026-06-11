#include <bits/stdc++.h>
using namespace std;

int abs(int x) {
  if(x >= 0) {
    return x;
  }
  else {
    return -1 * x;
  }
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int A, B, C;
  A = abs(a - b);
  B = abs(b - c);
  C = abs(a - c);
  if((A <= d) && (B <= d)) {
    cout << "Yes" << endl;
  }
  else if(C <= d) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

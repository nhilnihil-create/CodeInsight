#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d;
  
  /*
    if (abs(c - a) <= d || (abs (a - b) <= d && abs (b - c) <= d)) {
    cout << "Yes";
  } else {
    cout << "Yes";
  } cout << endl;
  */
  e = (abs(a - b) <= d ? 1 : 0)
    + (abs(b - c) <= d ? 1 : 0)
    + (abs(c - a) <= d ? 2 : 0);
  
  cout << (e >= 2 ? "Yes" : "No") << endl;
  return 0;
}
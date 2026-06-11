#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int distans = abs(b - a) + abs(b - c);

  if ((abs(a - c) <= d) || ((abs(b - a) <= d) && (abs(b - c) <= d))) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2;

  cin >> x1 >> y1 >> x2 >> y2;
  int a = x2 - x1;
  int b = y2 - y1;

  cout << x2 - b << " " <<  y2 + a << " " << x1 - b << " " << y1 + a << endl;
  return 0;
}

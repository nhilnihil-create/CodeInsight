#include <bits/stdc++.h>
using namespace std;


int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4, x, y;
  cin >> x1 >> y1 >> x2 >> y2;
  x = x2-x1; 
  y = y2-y1;
  x3 = x2-y;
  y3 = y2+x;
  x4 = x1-y;
  y4 = y1+x;
  cout << x3 << " " << y3 << " "<< x4 << " " << y4 << endl;
}

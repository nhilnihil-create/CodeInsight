#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  
  int vec_x = x2 - x1, vec_y = y2 - y1;
  
  x3 = x2 - vec_y, y3 = y2 + vec_x;
  x4 = x3 - vec_x, y4 = y3 - vec_y;
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << " " << endl;
  
}
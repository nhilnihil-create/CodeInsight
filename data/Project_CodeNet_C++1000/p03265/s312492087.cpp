#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3,y3,x4,y4;
  
  int n = x2 - x1;
  int m = y2 - y1;
  
  if (n >= 0) {
    if (m >= 0) {
      x3 = x2 - m;
      x4 = x3 - n;
      y3 = y2 + n;
      y4 = y3 - m;
    }
    else {
      x3 = x2 - m;
      x4 = x3 - n;
      y3 = y2 + n;
      y4 = y3 - m;
    }
  }
  else {
    if (m >= 0) {
      x3 = x2 - m;
      x4 = x3 - n;
      y3 = y2 + n;
      y4 = y3 - m;
    }
    else {
      x3 = x2 - m;
      x4 = x3 - n;
      y3 = y2 + n;
      y4 = y3 - m;
    }
  }
  cout << x3 << ' ' << y3  << ' '<< x4 << ' ' << y4 << ' '<< endl;
}
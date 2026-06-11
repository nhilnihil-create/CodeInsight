#include <bits/stdc++.h>
using namespace std;

int main() {
  long x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << x2+(y1-y2) << " ";//x3
  cout << y2+(x2-x1) << " ";//y3
  cout << x2+(y1-y2)+(x1-x2) << " ";//x4
  cout << y2+(x2-x1)+(y1-y2) << endl;//y4
}
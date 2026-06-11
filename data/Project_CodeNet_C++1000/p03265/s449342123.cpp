#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3 = 0;
  int y3 = 0;
  int x4 = 0;
  int y4 = 0;
  int a = 0;
  int b = 0;
  if(x2 >= x1 && y2 >= y1){
    a = x2 - x1;
    if (a < 0)
      a = a * (-1);
    b = y2 - y1;
    if (b < 0)
      b = b * (-1);
    x3 = x2 - b;
    y3 = y2 + a;
    x4 = x1 - b;
    y4 = y1 + a;
  }
  else if(x2 <= x1 && y2 >= y1){
    a = x1 - x2;
    if (a < 0)
      a = a * (-1);
    b = y2 - y1;
    if (b < 0)
      b = b * (-1);
    x3 = x2 - b;
    y3 = y2 - a;
    x4 = x1 - b;
    y4 = y1 - a;
  }
  else if(x2 <= x1 && y2 <= y1){
    a = x1 - x2;
    if (a < 0)
      a = a * (-1);
    b = y1 - y2;
    if (b < 0)
      b = b * (-1);
    x3 = x2 + b;
    y3 = y2 - a;
    x4 = x1 + b;
    y4 = y1 - a;
  } 
  else{
    a = x2 - x1;
    if (a < 0)
      a = a * (-1);
    b = y1 - y2;
    if (b < 0)
      b = b * (-1);
    x3 = x2 + b;
    y3 = y2 + a;
    x4 = x1 + b;
    y4 = y1 + a;
  }
  char s = ' ';
    cout << x3 << s << y3 << s <<  x4 << s <<  y4 << endl;
}
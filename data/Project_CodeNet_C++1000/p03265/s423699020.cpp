#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int a = x2 - x1;
  int b = y2 - y1;

  int x3, y3, x4, y4;


  x3 = x2 + -1  * b;
  y3 = y2 + a;

  int tmp;
  tmp = -1 * b;
  b = a;
  a = tmp;

  x4 = x3 + (- 1 * b);
  y4 = y3 + a;
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
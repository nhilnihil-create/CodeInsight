#include<bits/stdc++.h>
using namespace std;

int main (void){
  int x[5];
  int y[5];

  cin >> x[0] >> y[0] >> x[1] >> y[1];

  double l = 0,g = 0,j = 0,h = 0;
  int a = 0,b = 0;
  a = x[0] - x[1];
  b = y[0] - y[1];
  x[2] = b + x[1];
  y[2] = -a + y[1];
  a = x[1] - x[0];
  b = y[1] - y[0];
  x[3] = -b + x[0];
  y[3] = a + y[0];

  cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;

  return 0;


}
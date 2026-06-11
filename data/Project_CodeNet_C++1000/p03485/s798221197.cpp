#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int y;
  double a, b, x, z;
  
  cin >> a >> b ;
  
  x = (a + b)/2.0;
  y = (a + b)/2;
  z = x - y;
  
  if (z == 0.0){
    cout << y << endl;
  }
  
  else if (x - y > 0.0){
    cout << y + 1 << endl;
  }
}
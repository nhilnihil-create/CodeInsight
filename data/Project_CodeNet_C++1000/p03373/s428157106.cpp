#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int sum;
  if(a+b > 2*c) {
    if(x > y) {
      if(a > 2*c) sum = c * 2 * x;
      else sum = c * 2*y + a * (x-y);
    }
    else {
      if(b > 2*c) sum = c * 2 * y;
      else sum = c * 2*x + b * (y-x);
    }
  }
  else sum = a * x + b * y;
  
  cout << sum << endl;
  return 0;
}
#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int total = 0;
  if (a + b > 2*c) {
    if (x > y) {
      total += y*2*c;
      if (a >= 2*c) {
        total += (x-y)*2*c;
      }
      else {
        total += (x-y)*a;
      }
    }
    else if (x == y) {
      total += y*2*c;
    }
    else {
      total += x*2*c;
      if (b >= 2*c) {
        total += (y-x)*2*c;
      }
      else {
        total += (y-x)*b;
      }
    }
  }
  else if (a + b == 2*c) {
    if (x > y) {
      total += y*2*c;
      total += (x-y)*a;
    }
    else if (x == y) {
      total += y*2*c;
    }
    else {
      total += x*2*c;
      total += (y-x)*b;
    }
  }
  else {
    total += x*a + y*b;
  }
  cout << total << endl;
}
      
      

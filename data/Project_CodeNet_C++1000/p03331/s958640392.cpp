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
  int n;
  cin >> n;
  int a, b;
  int sum_a, sum_b;
  int min = 100000000000;
  for (int i = 1; i < n; i++) {
    a = i;
    b = n-a;
    //cout << a << endl;
    while(a>0) {
      sum_a += a % 10;
      a /= 10;
    }
    while(b>0) {
      sum_b += b % 10;
      b /= 10;
    }
    //cout << sum_a << " " << sum_b << endl;
    if (min > sum_a+sum_b) {
      min = sum_a + sum_b;
    }
    sum_a = 0;
    sum_b = 0;
  }
  cout << min << endl;
}

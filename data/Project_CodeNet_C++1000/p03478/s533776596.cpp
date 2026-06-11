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
  int n, a, b;
  cin >> n >> a >> b;
  //cout << n << a << b << endl;
  int sum_real = 0;
  for (int i = 1; i < n+1; i++) {
    int ii = i;
    //cout << ii << endl;
    int sum = 0;
    while(ii > 0) {
      sum += (ii % 10);
      ii /= 10;
    }
    if (a <= sum && sum <= b) {
      sum_real += i;
    }
  }
  cout << sum_real << endl;
}
      
      
    

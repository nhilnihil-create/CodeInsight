#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
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
  bool flag = true;
  rep(i, 26) {
    rep(j, 15) {
      int sum = i*4 + j*7;
      if(sum == n) {
        flag = false;
        coYes;
        break;
      }
    }
    if (flag == false) {
      break;
    }
  }
  if (flag) {
    coNo;
  }
}

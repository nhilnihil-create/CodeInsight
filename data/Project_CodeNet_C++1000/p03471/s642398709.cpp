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
  int n, y;
  cin >> n >> y;
  bool flag = true;
  bool flag_roop = false;
  rep(i, n+1) {
    rep(j, n+1) {
      int zan = y - 1000*i - 5000*j;
      if (zan >= 0) {
        if (zan%10000 == 0) {
          if (zan/10000+i+j == n) {
            cout << zan / 10000 << " " << j << " " << i << endl;
            flag = false;
            flag_roop = true;
            break;
          }
        }
      }
    }
    if (flag_roop) {
      break;
    }
  }
  if (flag) {
    cout << "-1 -1 -1" << endl;
  }
}

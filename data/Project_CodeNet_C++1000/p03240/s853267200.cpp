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
  vector<int> x(n);
  vector<int> y(n);
  vector<int> h(n);
  rep(i, n) {
    int xx, yy, hh;
    cin >> xx >> yy >> hh;
    x.at(i) = xx;
    y.at(i) = yy;
    h.at(i) = hh;
  }
  int cx, cy;
  int H;
  bool flag = false;
  rep(i, 101) {
    rep(j, 101) {
      cx = i;
      cy = j;
      rep(k, n) {
        if (h.at(k) > 0) {
          H = h.at(k) + abs(x.at(k) - cx) + abs(y.at(k) - cy);
          int count = 0;
          rep(l, n) {
            if (h.at(l) == max(H - abs(x.at(l) - cx) - abs(y.at(l) -cy), 0)) {
              count++;
            }
          }
          if (count == n) {
            cout << cx << " " << cy << " " << H << endl;
            flag = true;
            break;
          }
        }
      }
      if (flag) {
        break;
      }
    }
    if (flag) {
      break;
    }
  }
}
        
        
 
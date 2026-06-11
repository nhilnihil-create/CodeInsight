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
  vector<vector<int>> table(3, vector<int>(3));
  rep(i, 3) {
    rep(j, 3) {
      int c;
      cin >> c;
      table.at(i).at(j) = c;
    }
  }
  vector<int> a(3);
  vector<int> b(3);
  bool flag = false;
  rep(i, 101) {
    rep(j, 101) {
      rep(k, 101) {
        a.at(0) = i;
        a.at(1) = j;
        a.at(2) = k;
        b.at(0) = table.at(0).at(0) - a.at(0);
        b.at(1) = table.at(1).at(1) - a.at(1);
        b.at(2) = table.at(2).at(2) - a.at(2);
        int counta = 0;
        rep(ii, 3) {
          rep(jj, 3) {
            if (a.at(ii)+b.at(jj) == table.at(ii).at(jj)) {
              counta++;
            }
          }
        }
        if (counta == 9) {
          coYes;
          flag = true;
          break;
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
  if (!flag) {
    coNo;
  }
}
  
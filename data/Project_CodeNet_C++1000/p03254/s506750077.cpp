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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  bool flag = true;
  int count = 0;
  sort(a.begin(), a.end());
  rep(i, n) {
    x -= a.at(i);
    if (x < 0) {
      cout << i << endl;
      flag = false;
      break;
    }
    count++;
  }
  if ((count == n) && (flag)) {
    if (x > 0) {
      cout << count-1 << endl;
    }
    else {
      cout << count << endl;
    }
  }
  //cout << count << flag << endl;
}

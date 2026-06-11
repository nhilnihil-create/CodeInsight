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
  double n;
  cin >> n;
  double t, a;
  cin >> t >> a;
  vector<int> h(n);
  rep(i, n) {
    double num;
    cin >> num;
    h.at(i) = num;
  }
  double min = 10000000;
  int min_num = 0;
  rep(i, n) {
    double temp = t - 0.006*h.at(i);
    if (abs(temp - a) < min) {
      min = abs(temp - a);
      min_num = i+1;
    }
  }
  cout << min_num << endl;
}

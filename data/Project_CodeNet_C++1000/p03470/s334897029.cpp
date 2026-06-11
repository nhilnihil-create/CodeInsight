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
  vector<int> d(110);
  rep(i, n) {
    int num;
    cin >> num;
    d.at(i) = num;
  }
  vector<int> num(110, 0);
  rep(i, n) {
    num.at(d.at(i))++;
  }
  int ans = 0;
  rep(i, 101) {
    if (num.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}

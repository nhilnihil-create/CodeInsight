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
  vector<int> a(n);
  rep(i, n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  int sum_a = 0;
  int sum_b = 0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  rep(i, n) {
    if (i%2 == 0) {
      sum_a += a.at(i);
    }
    else {
      sum_b += a.at(i);
    }
  }
  cout << sum_a-sum_b << endl;
}

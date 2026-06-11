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
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int sum = 0;
  rep(i, n) {
    int num;
    cin >> num;
    sum += num;
    m.at(i) = num;
  }
  x -= sum;
  sort(m.begin(), m.end());
  cout << n + x/m.at(0) << endl;
}

      

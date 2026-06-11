#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
#include <cstdlib>  // abs() for integer
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
  int max = 0;
  rep(i, n) {
    rep(j, n) {
      if (abs(a.at(i) -a.at(j)) > max) {
        max = abs(a.at(i) - a.at(j));
      }
    }
  }
  cout << max << endl;
}

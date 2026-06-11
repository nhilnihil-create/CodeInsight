#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
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
  bool flag = true;
  int count = 0;
  while(flag) {
    rep(i, n) {
      if (a.at(i) % 2 == 1) {
        flag = false;
        break;
      }
      a.at(i) /= 2;
    }
    if (flag == false) {
      break;
    }
    count++;
  }
  cout << count << endl;
}

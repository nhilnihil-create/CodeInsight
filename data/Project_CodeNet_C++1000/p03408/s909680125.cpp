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
  vector<string> s(n);
  rep(i, n) {
    string ss;
    cin >> ss;
    s.at(i) = ss;
  }
  int m;
  cin >> m;
  vector<string> t(m);
  rep(i, m) {
    string tt;
    cin >> tt;
    t.at(i) = tt;
  }
  map<string, int> data;
  rep(i, n) {
    if (data.count(s.at(i))) {
      data.at(s.at(i))++;
    }
    else {
      data[s.at(i)] = 1;
    }
  }
  rep(i, m) {
    if (data.count(t.at(i))) {
      data.at(t.at(i))--;
    }
    else {
      data[t.at(i)] = -1;
    }
  }
  int max = -10000;
  for (pair<string, int> p : data) {
    string key = p.first;
    int value = p.second;
    //cout << key << value << endl;
    if (value > max) {
      max = value;
    }
  }
  if (max >= 0) { 
    cout << max << endl;
  }
  if (max < 0) {
    cout << 0 << endl;
  }
}

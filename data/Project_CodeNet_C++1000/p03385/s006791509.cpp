#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s;

  cin >> s;
  bool a = false;
  bool b = false;
  bool c = false;
  for (long long i = 0; i < 3; i++) {
    if (s.at(i) == 'a') {
      a = true;
    }
    if (s.at(i) == 'b') {
      b = true;
    }
    if (s.at(i) == 'c') {
      c = true;
    }
  }

  if (a && b && c) {
    cout << "Yes" << endl;

  } else {
    cout << "No" << endl;
  }
}

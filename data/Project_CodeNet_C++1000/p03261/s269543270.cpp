#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long n;
  cin >> n;

  vector<string> w(n);
  for (string &x : w) {
    cin >> x;
  }

  set<string> s;
  s.insert(w.at(0));
  for (long i = 1; i < n; i++) {
    if (s.find(w.at(i)) != s.end()) {
      cout << "No" << endl;
      return 0;
    }
    if (w.at(i - 1).at(w.at(i - 1).size() - 1) != w.at(i).at(0)) {
      cout << "No" << endl;
      return 0;
    }
    s.insert(w.at(i));
  }

  cout << "Yes" << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  map<string, int> ma;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (ma.count(s)) {
      ma[s]++;
    } else {
      ma[s] = 1;
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    if (ma.count(t)) {
      ma[t]--;
    } else {
      ma[t] = -1;
    }
  }
  int max = 0;
  for (auto x : ma) {
    if (max < x.second) {
      max = x.second;
    }
  }
  cout << max << endl;
}

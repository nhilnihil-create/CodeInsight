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
  int count = 0;
  if (s.at(0) == '1') {
    count++;
  }
  if (s.at(1) == '1') {
    count++;
  }
  if (s.at(2) == '1') {
    count++;
  }
  cout << count << endl;
}

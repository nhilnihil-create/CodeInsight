#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string n;
  cin >> n;

  char first = n.at(0);
  char last = n.at(3);
  string ans = "No";

  if (n.at(1) == first && n.at(2) == first) {
    ans = "Yes";
  }
  if (n.at(2) == last && n.at(1) == last) {
    ans = "Yes";
  }

  cout << ans << endl;
}

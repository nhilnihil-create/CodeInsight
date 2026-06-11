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
  for (int c = 0; c < 26; c++) {
    int tmp = n - 4 * c;
    if (tmp < 0) {
      continue;
    }
    if (tmp % 7 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}

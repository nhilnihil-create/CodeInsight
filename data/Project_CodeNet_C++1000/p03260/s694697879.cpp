#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int a, b;
  cin >> a >> b;
  int tmp = a * b;
  if (tmp * 1 % 2 == 1 || tmp * 2 % 2 == 1 || tmp * 3 % 2 == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

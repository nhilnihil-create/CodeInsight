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

  vector<long> l(87);
  l.at(0) = 2;
  l.at(1) = 1;
  for (long i = 2; i <= n; i++) {
    l.at(i) = l.at(i - 1) + l.at(i - 2);
  }

  cout << l.at(n) << endl;
}

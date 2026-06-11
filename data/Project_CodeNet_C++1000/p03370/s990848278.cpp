#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  for (int &x : m) {
    cin >> x;
  }
  int sum = 0;
  for (int x : m) {
    sum += x;
  }

  int min = m.at(0);
  for (int x : m) {
    if (x < min) {
      min = x;
    }
  }

  cout << (x - sum) / min + n << endl;
}

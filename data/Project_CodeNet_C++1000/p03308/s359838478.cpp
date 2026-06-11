#include <bits/stdc++.h>

#include <type_traits>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  int max = a.at(0);
  int min = a.at(0);

  for (int x : a) {
    if (x > max) {
      max = x;
    }
    if (x < min) {
      min = x;
    }
  }

  cout << max - min << endl;
}

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
  int T, A;
  cin >> T >> A;

  vector<int> H(n);
  for (int &x : H) {
    cin >> x;
  }

  int ret = 0;
  double min_diff = 10000000;
  for (int i = 0; i < n; i++) {
    double temp = T - H.at(i) * 0.006;
    double diff = A - temp;
    if (diff < 0) {
      diff = -diff;
    }

    if (diff < min_diff) {
      min_diff = diff;
      ret = i;
    }
  }
  cout << ++ret << endl;
}

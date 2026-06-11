// 081A
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long long n;
  cin >> n;

  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  ll count = 0;
  bool loop = true;
  while (loop) {
    for (auto &x : a) {
      if (x % 2 != 0) {
        loop = false;
        break;
      }
      x /= 2;
    }
    if (loop) {
      count++;
    }
  }
  cout << count << endl;
}

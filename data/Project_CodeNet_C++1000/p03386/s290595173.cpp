#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  set<ll> ans;
  for (long i = 1; i <= k && a + i - 1 <= b; i++) {
    ans.insert(a + i - 1);
  }

  for (long i = 1; i <= k && b - i + 1 >= a; i++) {
    ans.insert(b - i + 1);
  }
  for (auto x : ans) {
    cout << x << endl;
  }
}

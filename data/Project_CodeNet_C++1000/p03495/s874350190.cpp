#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> count(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    count.at(a)++;
  }
  sort(count.begin(), count.end());
  int c = 0;
  for (auto x : count) {
    if (x > 0) {
      c++;
    }
  }

  int ans = 0;
  int rem = c - k;
  for (auto x : count) {
    if (rem <= 0) {
      break;
    }
    if (x > 0) {
      ans += x;
      rem--;
    }
  }
  cout << ans << endl;
}

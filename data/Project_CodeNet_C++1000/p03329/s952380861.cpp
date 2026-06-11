#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, 100010);
  dp.at(0) = 0;
  for (int i = 1; i <= n; i++) {
    dp.at(i) = dp.at(i - 1) + 1;
    for (int j = 6; j <= i; j *= 6) {
      chmin(dp.at(i), dp.at(i - j) + 1);
    }
    for (int j = 9; j <= i; j *= 9) {
      chmin(dp.at(i), dp.at(i - j) + 1);
    }
  }

  cout << dp.at(n) << endl;
  return 0;
}
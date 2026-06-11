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
    int power = 1;
    while (power <= i) {
      chmin(dp.at(i), dp.at(i - power) + 1);
      power *= 6;
    }
    power = 1;
    while (power <= i) {
      chmin(dp.at(i), dp.at(i - power) + 1);
      power *= 9;
    }
  }

  cout << dp.at(n) << endl;
  return 0;
}
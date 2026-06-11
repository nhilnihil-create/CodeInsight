#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

const char A = 0;
const char B = 1;
const char C = 2;

// 0022
int main() {
  long long n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);

  for (long long i = 0; i < n; i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  vector<vector<ll>> dp(n, vector<ll>(3, 0));

  dp.at(0).at(A) = a.at(0);
  dp.at(0).at(B) = b.at(0);
  dp.at(0).at(C) = c.at(0);

  for (long long i = 1; i < n; i++) {
    dp.at(i).at(A) =
        max(dp.at(i - 1).at(B) + a.at(i), dp.at(i - 1).at(C) + a.at(i));
    dp.at(i).at(B) =
        max(dp.at(i - 1).at(A) + b.at(i), dp.at(i - 1).at(C) + b.at(i));
    dp.at(i).at(C) =
        max(dp.at(i - 1).at(A) + c.at(i), dp.at(i - 1).at(B) + c.at(i));
  }

  cout << max(max(dp.at(n - 1).at(A), dp.at(n - 1).at(B)), dp.at(n - 1).at(C))
       << endl;
}

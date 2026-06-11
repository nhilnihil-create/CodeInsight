#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, a, ans;

int main() {
  cin >> n;
  ans = 1;
  rep (i, n) {
    cin >> a;
    ans *= 2 - a%2;
  }
  ans = pow(3, n) - ans;
  cout << ans << endl;
  return 0;
}

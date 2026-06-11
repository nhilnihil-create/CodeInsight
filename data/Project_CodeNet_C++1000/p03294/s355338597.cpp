#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, a, ans;

int main() {
  cin >> n;
  ans = 0;
  rep (i, n) {
    cin >> a;
    ans += a;
  }
  ans -= n;
  cout << ans << endl;
  return 0;
}

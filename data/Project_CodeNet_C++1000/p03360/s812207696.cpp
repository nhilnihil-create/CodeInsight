#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int d = max( { a, b, c }), ans = a + b + c - d;
  rep(i,k)
    d *= 2;
  ans += d;
  cout << ans;
}

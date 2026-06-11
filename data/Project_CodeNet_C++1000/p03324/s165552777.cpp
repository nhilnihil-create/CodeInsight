#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int d, n, ans;

int main() {
  cin >> d >> n;
  ans = n;
  if (n == 100) ans++;
  rep (i, d) ans *= 100;
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int ds(int x) {
  int res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int ans = 1e9;
  for (int a = 1; a < n; a++) {
    int b = n - a;
    ans = min(ans, ds(a) + ds(b));
  }
  cout << ans << endl;
  return 0;
}
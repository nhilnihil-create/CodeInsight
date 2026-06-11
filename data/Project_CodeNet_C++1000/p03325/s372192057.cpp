#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int x) {
  int res = 0;
  while (x % 2 == 0) {
    x /= 2;
    ++res;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;
  rep(i, n) ans += f(a[i]);
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a[3];
  rep(i, 3) cin >> a[i];
  sort(a, a+3);
  int ans = 0;
  rep(i, 2) ans += abs(a[i+1] - a[i]);
  cout << ans << endl;
  return 0;
}
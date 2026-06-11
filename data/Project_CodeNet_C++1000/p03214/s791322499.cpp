#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int s = 0;
  rep(i, n) s += a[i];
  int ans = 0;
  rep(i, n) {
    if (abs(a[i] * n - s) < abs(a[ans] * n - s)) ans = i;
  }
  cout << ans << endl;
  return 0;
}
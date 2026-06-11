#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  int ans = 0;
  rep(i, n) {
    if (x - a[i] < 0) break;
    x -= a[i];
    ans = i+1;
  }
  if (ans == n && x > 0) ans--;
  cout << ans << endl;
  return 0;
}
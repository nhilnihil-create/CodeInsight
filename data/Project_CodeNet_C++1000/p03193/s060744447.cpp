#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = 0;
  rep(i, n) {
    if (a[i] >= h && b[i] >= w) ++ans;
  }
  cout << ans << endl;
  return 0;
}
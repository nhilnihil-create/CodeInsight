#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  int l, r;
  cin >> l >> r;
  rep(i,m-1) {
    int a,b;
    cin >> a >> b;
    l = max(l, a);
    r = min(r, b);
  }
  int ans = r-l+1;
  if (ans < 0) cout << 0 << endl;
  else cout << ans << endl;
  return 0;
}
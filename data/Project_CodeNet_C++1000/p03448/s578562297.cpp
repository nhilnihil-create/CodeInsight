#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  for(int i = 0; i <= a; ++i)
    for(int j = 0; j <= b; ++j)
      for(int k = 0; k <= c; ++k)
        if(i*500 + j*100 + k*50 == x) ans++;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) solve();

  return 0;
}

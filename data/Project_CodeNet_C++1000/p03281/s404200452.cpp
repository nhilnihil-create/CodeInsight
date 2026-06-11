#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n;
  cin >> n;

  int ans = 0;
  for(int i = 3; i <= n; i+=2) {
    int count = 0;
    for(int j = 1; j <= i; ++j) {
      if(i%j == 0) count++;
    }
    if(count == 8) {
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}

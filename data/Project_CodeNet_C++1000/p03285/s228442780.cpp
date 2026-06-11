#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n;
  cin >> n;
  for(int i=0; i<=n/4; ++i) {
    for(int j=0; j<=n/7; ++j) {
      if(n - (i*4 + j*7) == 0) drop("Yes");
    }
  }
  cout << "No" << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}

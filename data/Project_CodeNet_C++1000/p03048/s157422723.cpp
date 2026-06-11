#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int R, G, B, N; cin >> R >> G >> B >> N;
  
  int ans = 0;
  rep(r, N+1) rep(g, N+1) {
    if(N-r*R-g*G >= 0 && (N-r*R-g*G)%B == 0) ans++;
  }
  cout << ans << endl;
}

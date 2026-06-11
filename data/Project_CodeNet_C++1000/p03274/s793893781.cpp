#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int N, K; cin >> N >> K;
  vector<int> x(N);
  rep(i, N) cin >> x[i];
  
  int z = 0;
  while(z < N-1 && x[z] < 0) z++;
  
  if(z == 0) cout << x[K-1] << endl;
  else if(z == N-1) cout << -x[N-K] << endl;
  else {
    int ans = pow(10, 17);
    rep(i, K) {
      if(z-i >= 0 && z+K-i-1 <= N-1) {
        ans = min(ans, x[z+K-i-1]+abs(2*x[z-i]));
        ans = min(ans, 2*x[z+K-i-1]+abs(x[z-i]));
      }
    }
    cout << ans << endl;
  }

}
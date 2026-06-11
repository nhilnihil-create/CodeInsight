#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> C(N-1), S(N-1), F(N-1);
  rep(i, N-1) cin >> C[i] >> S[i] >> F[i];
  
  vector<int> ans(N, 0);
  
  rep(i, N-1) {
    int t = 0;
    rep(j, N-i-1) {
      while(!(t >= S[i+j] && t%F[i+j] == 0)) t++;
      t += C[i+j];
    }
    ans[i] = t;
  }
  
  rep(i, N) cout << ans[i] << endl;

}
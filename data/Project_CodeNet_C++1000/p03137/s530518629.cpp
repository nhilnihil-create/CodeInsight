#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N, M; cin >> N >> M;
  vector<int> X(M);
  rep(i, M) cin >> X[i];
  
  sort(all(X));
  
  vector<int> Y(M-1);
  rep(i, M-1) Y[i] = X[i+1]-X[i];
  
  sort(all(Y));
  
  int ans = 0;
  rep(i, M-N) ans += Y[i];
  
  cout << ans << endl;
  
}

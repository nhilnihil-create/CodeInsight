#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  vector<int> m(5, 0);
  rep(i, N) {
    if(S[i][0] == 'M') m[0]++;
    if(S[i][0] == 'A') m[1]++;
    if(S[i][0] == 'R') m[2]++;
    if(S[i][0] == 'C') m[3]++;
    if(S[i][0] == 'H') m[4]++;
  }
  
  int ans = 0;
  
  rep(i, 5) rep(j, 5) rep(k, 5) {
    if(i != j && j != k && k != i) {
      ans += m[i]*m[j]*m[k];
    }
  }
  
  

  cout << ans/6 << endl;

}

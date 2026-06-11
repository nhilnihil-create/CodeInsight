#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string S; cin >> S;
  int N = S.size();
  
  int w = 0;
  int ans = 0;
  rep(i, N) {
    if(S[i] == 'W') {
      ans += i-w;
      w++;
    }
  }
  if(w == N) {
    cout << 0 << endl;
    return 0;
  }
  cout << ans << endl;


}
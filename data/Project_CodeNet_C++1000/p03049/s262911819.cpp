#include <bits/stdc++.h>
using namespace std;
#define rep(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  int fb=0, ea=0, n=0;
  string s;
  int ans = 0;
  rep(i, 0, N) {
    cin >> s;
    if(s[0] == 'B') {
      fb++;
    }
    if(s[s.size()-1] == 'A') {
      ea++;
    }
    if(s[s.size()-1] == 'A' || s[0] == 'B') {
      n++;
    }
    rep(j, 0, s.size()-1) {
      if(s[j] == 'A' && s[j+1] == 'B') ans++;
    }
  }
  int k=0;
  ans += min(min(fb, ea), max(k, n-1));
  cout << ans << endl;
      
}
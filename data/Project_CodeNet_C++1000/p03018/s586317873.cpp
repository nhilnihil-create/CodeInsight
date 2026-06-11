#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG


signed main() {
  string s; cin >> s;
  
  int ans = 0;
  int a = 0;
  int b = 0;
  
  rep(i, s.size()) {
    if(s[i] == 'A') {
      a++;
      b = 0;
    }
    else if(s[i] == 'B') {
      b++;
      if(i < s.size()-1 && s[i+1] != 'C') a = 0;
    }
    else {
      if(a > 0 && b == 1) {
        ans += a;
      } else {
        a = 0;
      }
      b = 0;
    }
  }
  
  
  cout << ans << endl;
}

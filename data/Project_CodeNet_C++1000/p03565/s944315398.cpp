#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s, t, res = "UNRESTORABLE";
  cin >> s >> t;
  int n = s.size(), m = t.size();
  for (int i=n-m; i>=0; i--){
    bool ok = true;
    rep(j, m){
      if (s[i+j] == t[j] || s[i+j] == '?') continue;
      ok = false;
      break;
    }
    if (ok){
      rep(j, m) s[i+j] = t[j];
      rep(j, n) if (s[j] == '?') s[j] = 'a';
      res = s;
      break;
    }
  }
  cout << res << endl;
  return 0;
}

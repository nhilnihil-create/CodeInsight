#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  ll ans = 0;
  REP(b,n){
    vector<string> t(n);
    REP(i,n) t[i] = s[i].substr(b+1) + s[i].substr(0, b+1);
    
    bool flag = true;
    REP(i,n) REP(j,n){
      if(t[i][j]!=t[j][i]) flag = false;
    }
    if(flag) ans += n;
  }
  cout << ans << '\n';
  return 0;
}

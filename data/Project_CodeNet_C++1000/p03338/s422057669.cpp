#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  map<char,int> l,r;
  int ans = 0, cnt = 0;
  rep(i,n) r[s[i]]++;
  rep(i,n-1) {
    if (!l.count(s[i])) cnt++;
    l[s[i]]++;
    r[s[i]]--;
    if (r[s[i]] == 0) cnt--;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;

  
  
  
  
  
  
  
  
  
  
  
  
  
}
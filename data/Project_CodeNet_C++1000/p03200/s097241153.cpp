#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin>>s;
  ll r=s.size()-1, wc=0, ans=0;
  rep(i,s.size()) if (s[i] =='W') wc++;
  rep(l,wc) {
    if (s[l] == 'B') {
      while(1) {
        if (s[r] == 'W') {
          ans += r-l;
          r--;
          break;
        }
        r--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
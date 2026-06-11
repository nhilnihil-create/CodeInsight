#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,m;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  cin >> m;
  vector<string> t(m);
  rep(i,m) cin >> t[i];
  int ans = 0;
  rep(i,n){
    int cnt = 0;
    rep(j,n){
      if(s[i] == s[j])cnt++;
    }
    rep(j,m){
      if(s[i] == t[j])cnt--;
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
}
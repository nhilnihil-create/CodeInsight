#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<string,string>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  string l = "", r = "";
  rep(i,n) {
    l += s[i];
    r += s[2*n-1-i];
  }
  map<P,ll> m;
  ll ans = 0;
  rep(i,1<<n) {
    string a = "", b = "";
    rep(j,n) {
      if(i & (1<<j)) a += l[j];
      else b += l[j];
    }
    m[P(a,b)]++;
  }
  rep(i,1<<n) {
    string a = "", b = "";
    rep(j,n) {
      if(i & (1<<j)) a += r[j];
      else b += r[j];
    }
    ans += m[P(a,b)];
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, q; string s;
  cin >> n;
  cin >> s;
  cin >> q;
  int k[q];
  rep(i,q) cin >> k[i];
  rep(i,q) {
    ll a = 0;
    ll nm = 0, nd = 0, dm = 0;
    rep(j,k[i]) {
      if(s[j] == 'D') {
        nd++;
      } else if(s[j] == 'M') {
        nm++;
        dm += nd;
      } else if(s[j] == 'C') {
        a += dm;
      }
    }
    for(int j = 1; j <= n-k[i]; j++) {
      if(s[j-1] == 'D' && s[j+k[i]-1] == 'D') {
        dm -= nm;
      } else if(s[j-1] == 'D' && s[j+k[i]-1] == 'M') {
        dm -= nm; nd--; nm++; dm += nd;
      } else if(s[j-1] == 'M' && s[j+k[i]-1] == 'D') {
        nd++; nm--;
      } else if(s[j-1] == 'M' && s[j+k[i]-1] == 'M') {
        dm += nd;
      } else if(s[j+k[i]-1] == 'D') {
        nd++;
      } else if(s[j-1] == 'D') {
        nd--; dm -= nm;
      } else if(s[j+k[i]-1] == 'M') {
        nm++; dm += nd;
      } else if(s[j-1] == 'M') {
        nm--;
      }
      if(s[j+k[i]-1] == 'C') {
        a += dm;
      }
    }
    cout << a << endl;
  }
  return 0;
}
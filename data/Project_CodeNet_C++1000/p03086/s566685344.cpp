#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  rep(i,0,n) rep(j,i,n) {
    bool flag = true;
    rep(k,i,j+1) {
      if (s[k] != 'A' && s[k] != 'C' && s[k] != 'G' && s[k] != 'T') {
        flag = false;
      }
    }
    if (flag) {
      ans = max(ans,j-i+1);
    }
  }
  cout << ans << endl;
  return 0;
}

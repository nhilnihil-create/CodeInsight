#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  string s;
  int cnt=0;
  int ans=0;
  cin >> s;
  rep(i, (int)s.size()){
    if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') cnt++;
    else cnt=0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

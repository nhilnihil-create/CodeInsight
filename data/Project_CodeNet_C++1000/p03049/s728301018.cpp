#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<string> s(n);
  int ans1 = 0, acnt = 0, bcnt = 0, abcnt = 0;
  rep(i, n) cin >> s[i];
  bool ok = false;
  rep(i, n){
    rep(j, s[i].size() - 1){
      if(s[i][j] == 'A' && s[i][j + 1] == 'B') ans1++;
    }
    if(s[i][s[i].size() - 1] == 'A' && s[i][0] == 'B') abcnt++;
    if(s[i][s[i].size() - 1] == 'A' && s[i][0] != 'B') acnt++;
    if(s[i][s[i].size() - 1] != 'A' && s[i][0] == 'B') bcnt++;
  }
  int ans2 = min(acnt, bcnt);
  if(acnt > 0 || bcnt > 0) ans2 += abcnt;
  else ans2 += max(abcnt - 1, 0);
  cout << ans1 + ans2 << endl;
  return 0;
}

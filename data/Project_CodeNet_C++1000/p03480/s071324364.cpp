#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
const int INF = 1e9;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  int ans = INF;
  rep(i, n-1){
    if(s[i] != s[i+1]){
      int m = max(i+1,n-i-1);
      ans = min(m, ans);
    }
  }
  if(ans == INF) cout << n << endl;
  else cout << ans << endl;
  return 0;
}

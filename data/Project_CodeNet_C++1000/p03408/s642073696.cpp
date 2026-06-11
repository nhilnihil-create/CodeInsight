#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  cin >> m;
  vector<string> t(m);
  rep(i, m) cin >> t[i];
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int scnt = 1;
    int tcnt = 0;
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      if(s[i] == s[j]) scnt++;
    }
    for(int j = 0; j < m; j++) {
      if(s[i] == t[j]) tcnt--;
    }
    ans = max(ans, scnt+tcnt);
  }
  
  cout << ans << endl;
  return 0;
} 
  
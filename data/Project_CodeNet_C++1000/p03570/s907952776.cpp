#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const int INF = 1e9;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  vector<int> mp(1<<26,INF);
  vector<int> dp(n+1,INF);
  int v = 0;
  mp[0] = 0;
  rep(i,n) {
    int c = s[i] - 'a';
    v ^= (1<<c);
    rep(j,26) {
      int b = v ^ (1<<j);
      if(mp[b] < INF) dp[i+1] = min(dp[i+1],mp[b]+1);
    }
    mp[v] = min(mp[v],dp[i+1]);
  }
  cout << (v == 0 ? 1 : dp[n]) << endl;
  return 0;
}
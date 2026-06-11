#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string s, t; cin >> s >> t;
  vector<vi> dp(sz(s)+1, vi(sz(t)+1,0));
  rep(i,1,sz(s)+1){
    rep(j,1,sz(t)+1){
      if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  string res = "";
  int i = sz(s), j = sz(t);
  while(i && j){
    if(s[i-1] == t[j-1]){
      res += s[i-1];
      i--; j--;
    }
    else{
      if(dp[i][j-1] > dp[i-1][j]) j--;
      else i--;
    }
  }
  reverse(all(res));
  cout << res << "\n";
}

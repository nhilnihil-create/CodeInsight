#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

string s;
string r;
ll t;
ll dp[302][302][302];
ll ans;

int main(){
  cin >> s;
  cin >> t;
  r = s;
  reverse(r.begin(),r.end());
  // cerr << r << endl;
  // cerr << s << endl;
  for(ll i = 0;i < s.size();i++){
    for(ll j = 0;j < s.size();j++){
      for(ll k = 0;k <= t;k++){
        if(s[i] == r[j]){
          dp[i+1][j+1][k] = max(dp[i+1][j+1][k],dp[i][j][k]+1);
        }else{
          dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1],dp[i][j][k]+1);
        }
        dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
        dp[i][j+1][k] = max(dp[i][j+1][k],dp[i][j][k]);
      }
    }
  }
  // cerr << s.size() << endl;
  // for(ll k = 0;k <= t;k++){
  //   for(ll i = 0;i <= s.size();i++){
  //     for(ll j = 0;j <= s.size();j++){
  //       cerr << dp[i][j][k] << " ";
  //     }
  //     cerr << endl;
  //   }
  //   cerr << endl;
  //   cerr << endl;
  // }

  for(ll i = 0;i < s.size();i++){
    for(ll k = 0;k <= t;k++){
      ans = max(ans,dp[i][s.size()-i-1][k]*2+1);
    }
  }
  for(ll i = 1;i < s.size();i++){
    for(ll k = 0;k <= t;k++){
      ans = max(ans,dp[i][s.size()-i][k]*2);
    }
  }
  cout << ans << endl;

}

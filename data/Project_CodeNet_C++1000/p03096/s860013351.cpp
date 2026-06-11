#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  vvint places(210000);
  int n;
  cin >> n;
  vint C(n);
  rep(i,0,n) cin >> C[i];
  rep(i,0,n) places[C[i]].push_back(i);

  vint dp(210000);
  dp[0] = 1;
  for(int i = 1;i <= n;i++){
    dp[i] += dp[i-1];
    dp[i] %= MOD;

    int k = lower_bound(places[C[i-1]].begin(),places[C[i-1]].end(),i-1) - places[C[i-1]].begin();
    if(k > 0){
      int j = places[C[i-1]][k-1];
      if((i-1) - j > 1){
        dp[i] += dp[j+1];
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[n] << endl;  
}
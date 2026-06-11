#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  string s;
  cin >> n >> s;
  vector<vector<ll>> dp(3010, vector<ll>(3010,0));
  //dp[i][j]=(i番目まで決めたとき、i番目の数より大きいものがj個残っているような場合の数)
  rep(i,n){ dp[1][i]=1; }
  
  for(int i=1; i<n; i++){
    ll rsk[3010];   //ruisekiwa
    rep(j,n-i+1){ rsk[j+1]=(rsk[j]+dp[i][j])%mod;}
    if(s[i-1]=='<'){
//      rep(k,n-1)for(int j=k+1; j<n-i+1; j++){ (dp[i+1][k]+=dp[i][j])%=mod;}
      rep(k,n-1){ dp[i+1][k]=(rsk[n-i+1]-rsk[k+1])%mod;}
    } else {
//      rep(k,n-i)for(int j=0; j<k+1; j++){ (dp[i+1][k]+=dp[i][j])%=mod;}
      rep(k,n-i){ dp[i+1][k]=rsk[k+1]; }
    }
  }
  
  ll ans = (dp[n][0]+mod)%mod;
  cout << ans << endl;
  return 0;
}
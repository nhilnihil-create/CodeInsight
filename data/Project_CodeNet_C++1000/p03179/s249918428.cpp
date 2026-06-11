#include<bits/stdc++.h>
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define pb push_back
ll dp[3005][3005];
const ll mod = 1000000007;
int main(){
    	int n;
    	string s;
    	cin>>n>>s;
    	dp[1][1] = 1;
    	s = "  " + s;
    	for(int i=2;i<=n;i++){
        if(s[i]=='<'){
            ll res = 0;
            for(int j=1;j<=i;j++){
              dp[i][j] += res;
              dp[i][j] %= mod;
              res += dp[i-1][j];
            }
        }
        else{
            ll res = 0;
            for(int j=i;j>=1;j--){
               res += dp[i-1][j];
               dp[i][j] += res;
               dp[i][j] %= mod;
            }
        }
    	}
    	ll ans = 0;
    	for(int i=1;i<=n;i++) ans += dp[n][i];
    	ans %= mod;
    	cout<<ans<<'\n';

}






#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n;
string s;
ll dp[3005][3005];
void mplus(int& a,ll b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}
int main(){
	cin>>n>>s;
	s=' '+s;
	dp[1][1]=1;
	for(int i=2;i<=n;++i){
		if(s[i-1]=='<'){
			dp[i][1]=0;
			for(int j=2;j<=i;++j){
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
			}
		}
		else{
			dp[i][i]=0;
			for(int j=i-1;j>=1;--j){
				dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		mplus(ans,dp[n][i]);
	}
	cout<<ans<<'\n';
	return 0;
}
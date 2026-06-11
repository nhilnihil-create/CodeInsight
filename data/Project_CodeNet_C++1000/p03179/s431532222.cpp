#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long dp[4096][4096];
const int mod=1e9+7;

int main(){
	cin>>n;
	cin>>s;
	dp[1][1]=1;
	for(int i=2;i<=n;++i){
		if(s[i-2]=='<'){
			dp[i][1]=0;
			for(int j=2;j<=i;++j)
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
			}
		else {
			dp[i][i]=0;
			for(int j=i-1;j>=1;--j)
				dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;++i) ans+=dp[n][i],ans%=mod;
	cout<<ans<<'\n';
	return 0;
}
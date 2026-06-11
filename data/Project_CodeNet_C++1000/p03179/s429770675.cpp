#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=4096;
const int MOD=1e9+7;
LL dp[MAXN][MAXN],sum[MAXN][MAXN],n;
string s;

int main(){
	cin>>n>>s;
	s='$'+s;
	dp[1][1]=sum[1][1]=1;
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i-1]=='<'){
			/*	for(int k=0;k<j;k++){
					dp[i][j]+=dp[i-1][k];
					dp[i][j]%=MOD;
				}*/
				dp[i][j]=sum[i-1][j-1]%MOD;
			}
			else{
			/*	for(int k=j;k<=i-1;k++){
					dp[i][j]+=dp[i-1][k];
					dp[i][j]%=MOD;
				}*/
				dp[i][j]=(sum[i-1][i-1]-sum[i-1][j-1]+MOD)%MOD;
			}
			sum[i][j]=(sum[i][j-1]+dp[i][j])%MOD;
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[n][i];
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=3005;
const int MOD=1e9+7;
int n,dp[N][N],ans; 
char s[N];
int main() {
	scanf("%d%s",&n,s+1);
	dp[0][1]=1;
	for(int i=1;s[i];i++){
		int pre[N]={0};
		for(int j=1;j<=i+1;j++)pre[j]=(pre[j-1]+dp[i-1][j])%MOD;
		if(s[i]=='<'){
			for(int j=1;j<=i+1;j++){
				dp[i][j]=pre[j-1];
			}
		} else {
			for(int j=1;j<=i+1;j++){
				dp[i][j]=(pre[i+1]-pre[j-1]+MOD)%MOD;
			}
		}
		if(i==n-1)for(int j=1;j<=n;j++)(ans+=dp[i][j])%=MOD;
	}
	cout<<ans<<endl;
}
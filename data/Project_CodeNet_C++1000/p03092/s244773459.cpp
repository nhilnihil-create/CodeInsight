#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[5005][5005],a,b;
int n,p[5005],pos[5005];

int main(){
	scanf("%d %lld %lld",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=1e18;
			if(j==pos[i]){dp[i][j]=min(dp[i][j],dp[i-1][j-1]);}
			dp[i][j]=min(dp[i][j],dp[i-1][j]+((j<pos[i])?b:a));
		}
		for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][j-1]);
	}
	printf("%lld\n",dp[n][n]); 

	return 0;
}
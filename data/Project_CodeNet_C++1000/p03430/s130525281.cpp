#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[305];
inline void init(){
	gets(s+1);
	n=strlen(s+1);
	scanf("%d",&m);
}

int dp[305][305][305],ans;
inline void solve(){
	for(int k=0;k<=m;++k)
		for(int i=1;i<=n;++i)
			for(int j=n;j>=i;--j){
				int &f=dp[i][j][k];
				f=max(dp[i-1][j][k],dp[i][j+1][k]);
				if(s[i]==s[j])f=max(f,dp[i-1][j+1][k]+1);
				else if(k)f=max(f,dp[i-1][j+1][k-1]+1);
				ans=max(ans,i==j?f*2-1:f*2);
			}
	printf("%d\n",ans);
}

int main(){
	init();
	solve();
	return 0;
} 
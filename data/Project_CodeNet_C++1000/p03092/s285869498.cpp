#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;
typedef long long ll;
cs ll INF = 1e18;
cs int N = 5e3 + 50;
int n, A, B; ll dp[N];
int main(){
	#ifdef FSYolanda
	freopen("1.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&A,&B);
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	for(int i=1,x; i<=n; i++){
		scanf("%d",&x);ll mn=INF;
		for(int j=0; j<=x; j++)mn=min(mn,dp[j]);
		for(int j=0; j<x; j++)dp[j]+=A;
		for(int j=x+1; j<=n; j++)dp[j]+=B;dp[x]=mn;
	} ll ans=INF;
	for(int i=0;i<=n;i++)ans=min(ans,dp[i]);
	cout<<ans; return 0;
}
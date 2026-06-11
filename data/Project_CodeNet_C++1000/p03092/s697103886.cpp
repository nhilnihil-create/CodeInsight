#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
ll dp[N][N];
int P[N],D[N];
const ll INF=1e18;
int main()
{
	int n,A,B;scanf("%d%d%d",&n,&A,&B);
	for(int i=0;i<n;i++)scanf("%d",&D[i]);
	int tar=0;
	for(int i=0;i<n;i++){
		tar++;int cnt=0;
		for(int j=0;j<n;j++){
			if(D[j]==tar){
				P[tar]=n-tar-cnt;
				break;
			}else if(D[j]>tar)cnt++;
		}
	}fill(&dp[0][0],&dp[N-1][N],INF);
	for(int i=0;i<=n;i++)dp[0][i]=0;
	for(int i=1;i<=n;i++){
		ll M=INF;
		for(int j=0;j<=n;j++){
			M=min(M,dp[i-1][j]);
			//n-j,P[i]
			if(P[i]+1==n-j)dp[i][j+1]=min(dp[i][j+1],M);
			else if(P[i]+1<n-j)dp[i][j+1]=min(dp[i][j+1],M+B);
			else dp[i][j]=min(dp[i][j],M+A);
		}
	}cout<<dp[n][n]<<'\n';
}

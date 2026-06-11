#include<bits/stdc++.h>
using namespace std;
const int N=5010;
typedef long long ll;
ll dp[N][N];
int f[N][N],n,A,B,a[N],b[N];
int main(){
	cin>>n>>A>>B;
	for(int i=1;i<=n;++i)cin>>a[i],b[a[i]]=i;
	for(int i=n;i;--i)
		for(int j=1;j<=n;++j)f[i][j]=f[i+1][j]+(a[i]>j);
	memset(dp,0x3f,sizeof dp);memset(dp[n+1],0,sizeof dp[n+1]);
	for(int i=n;i;--i){
		dp[i][n+1]=0;
		for(int j=n;j;--j)
			if(a[i]<j)dp[i][j]=dp[i+1][j];
			else if(b[j]<i)dp[i][j]=dp[i][j+1];
			else{
				int u=b[j];
				if(u==i)dp[i][j]=dp[i+1][j+1];
				else dp[i][j]=min(dp[i][j+1]+B,dp[u+1][j+1]+(ll)A*(f[i][j]-f[u][j]));
			}
	}
	cout<<dp[1][1]<<endl;
	return 0;
}


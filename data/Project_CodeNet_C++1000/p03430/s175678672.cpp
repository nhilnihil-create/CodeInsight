#include<iostream>
#include<algorithm>
using namespace std;
string s;
int K;
int dp[301][301][301];
main()
{
	cin>>s>>K;
	int N=s.size();
	for(int i=0;i<=N;i++)for(int k=0;k<=N;k++)for(int j=0;j<=K;j++)dp[i][k][j]=-1e9;
	dp[0][N-1][K]=0;
	int ans=0;
	for(int i=0;i<N;i++)for(int j=N-1;j>=0&&j>=i-1;j--)for(int k=0;k<=K;k++)
	{
		if(dp[i][j][k]<0)continue;
		ans=max(ans,dp[i][j][k]+(i<=j));
		dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
		if(j>0)dp[i][j-1][k]=max(dp[i][j-1][k],dp[i][j][k]);
		if(i<j)dp[i+1][j-1][k-(s[i]!=s[j])]=max(dp[i+1][j-1][k-(s[i]!=s[j])],dp[i][j][k]+2);
	}
	cout<<ans<<endl;
}
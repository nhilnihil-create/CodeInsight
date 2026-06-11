#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	vector<vector<int> >dp(n,vector<int>(3));
	dp[0][0]=a,dp[0][1]=b,dp[0][2]=c;
	
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		
		dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a;
		dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b;
		dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c;
	}
	
	printf("%d\n",*max_element(dp[n-1].begin(),dp[n-1].end()));
	
	return 0;
}

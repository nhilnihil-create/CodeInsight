#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	
	vector<int> v(n+1);
	
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	
	vector<int> dp(n+1);
	
	dp[1] = 0;
	int x = fabs(v[1]-v[2]);
	dp[2] = x;
	
	for(int i=3;i<=n;i++)
	dp[i] = min(dp[i-1]+fabs(v[i]-v[i-1]),dp[i-2]+fabs(v[i]-v[i-2]));
	
	printf("%d\n",dp[n]);
	
	return 0;
}
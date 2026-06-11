#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	
	vector<int> v(n+1);
	
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	
	vector<int> dp(n+1,INT32_MAX);
	
	dp[1] = 0;
    dp[2] = fabs(v[1]-v[2]);
	
	for(int i=3;i<=n;i++)
	{
	    for(int j=1;j<=k;j++)
	    {
	        if(i-j<1)
	        break;
	        
	        int dx = fabs(v[i]-v[i-j]);
	        dp[i] =min(dp[i],dp[i-j]+dx);
	    }
	}
	printf("%d\n",dp[n]);
	
	return 0;
}
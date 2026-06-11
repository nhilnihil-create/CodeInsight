#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int a[102],dp[102][100004],s[102][100005];
signed main()
{
	int n,i,j,k,w=0,t;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=k+1;i++)
	s[0][i]=1;
	for(i=1;i<=n;i++)
	for(j=0;j<=k;j++)
	{   
	    int v=s[i-1][j+1]-s[i-1][max(w,j-a[i])];
	    if(v<0)
	    v=v+1000000007;
	    dp[i][j]=(v+dp[i][j])%1000000007;
	    s[i][j+1]=(s[i][j]+dp[i][j])%1000000007;
	    
	}
	cout<<dp[n][k]<<"\n";
}

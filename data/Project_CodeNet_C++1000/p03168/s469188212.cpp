#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    double a[n+1];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    double dp[n+1][n+1],ans=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=i;j++)
    	{
    		if(j==0)
    		{
    			dp[i][j]=dp[i-1][j]*(1-a[i]);
    		}
    		else
    		{
    			dp[i][j]=dp[i-1][j]*(1-a[i])+dp[i-1][j-1]*a[i];
    		}
    	}
    }
    for(int i=(n+1)/2;i<=n;i++)
    {
    	ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    int s[n];
    s[0]=a[0];
    for(i=1;i<n;i++) s[i]=s[i-1]+a[i];
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    
    for(i=0;i<n;i++) dp[i][i]=a[i];
    for(i=1;i<n;i++) dp[i-1][i]=a[i]+a[i-1];

    for(i=2;i<n;i++)
    {
    	for(j=0;j+i<n;j++)
    	{
    		dp[j][j+i]=inf;
    		for(k=j;k<(i+j);k++)
    		{
    			int ans=dp[j][k]+dp[k+1][j+i]+s[k]-s[j]+a[j]+s[j+i]-s[k+1]+a[k+1];
    			if(k==j) ans-=a[k];
    			if(k+1==(i+j)) ans-=a[i+j];
    			dp[j][j+i]=min(dp[j][j+i],ans);
    		}
    	}
    }
    cout<<dp[0][n-1]<<endl;





	return 0;
}

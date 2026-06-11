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
    int n,k,i;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    vector<int> v(n+1);
    for(i=1;i<=n;i++) cin>>v[i];
    for(i=0;i<=k;i++)
    {
    	dp[1][i]=(i<=v[1])?1:0;
    }

    for(i=2;i<=n;i++)
    {
    	dp[i][0]=1;
    	for(int j=1;j<=k;j++)
    	{
    		dp[i][j]=(dp[i][j-1]+dp[i-1][j]-((j-v[i]-1>=0)?dp[i-1][j-v[i]-1]:0)+mod)%mod;
    	}
    }
    cout<<dp[n][k]<<endl;
	return 0;
}

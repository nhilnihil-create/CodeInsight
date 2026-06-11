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
    string a,b;
    int i,j;
    cin>>a>>b;
 
    int n=a.length();
    int m=b.length();
 
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(i=0;i<=n;i++) dp[i][0]=0;
    for(i=0;i<=m;i++) dp[0][i]=0;
 
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=m;j++)
    	{
    		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    		if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
    	}
    }

    string ans="";
 
    i=n;j=m;
    while(i>=1 && j>=1)
    {
    	if(a[i-1]==b[j-1]) {ans+=a[i-1]; i-=1; j-=1;}
    	else if(dp[i-1][j]>dp[i][j-1])  i-=1;
    	else j-=1;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
 
 
	return 0;
}
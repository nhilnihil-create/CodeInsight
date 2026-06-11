#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

db dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1,t=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j,n;
    	cin>>n;
    	vector<db>p(n+1);
    	rep(i,1,n) cin>>p[i];
    	memset(dp,0,sizeof(dp));
    	// i tosses j heads
    	dp[0][0]=1;
    	rep(i,1,n) dp[i][0]=dp[i-1][0]*(1-p[i]);
    	rep(i,1,n)
    	{
    		rep(j,1,n)
    		{
    			dp[i][j]+=dp[i-1][j-1]*(p[i]);
    			dp[i][j]+=dp[i-1][j]*(1-p[i]);
    		}
    	}
    	db ans=0.0;
    	rep(i,n,n)
    	{
    		rep(j,n/2 +1,n) ans+=dp[i][j];
    	}
    	cout<<setprecision(12)<<ans;

    }
    	return 0;
    
}
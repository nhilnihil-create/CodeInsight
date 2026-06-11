#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
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

ll mod=1e9+7;
ll dp[3001][3001],pre[3001][3001];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,n;
    	cin>>n;
    	string s;
    	cin>>s;
    	// dp[i][j] tells us the no of ways to construct the permutation using first
    	// i elements and the permutation ends with j
    	dp[1][1]=1;
    	rep(len,2,n)
    	{
    		rep(i,1,len-1)
    		{
    			pre[len-1][i]=(pre[len-1][i-1] + dp[len-1][i])%mod;
    			// pre[len-1][i]%=mod;
    		}
    		rep(end,1,len)
    		{
    			ll left,right;
    			if(s[len-2]=='<')
    			{
    				left=1;
    				right=end-1;
    			}
    			else
    			{
    				left=end;
    				right=len-1;
    			}
    			if(left<=right)
    			{
    				dp[len][end]+=(pre[len-1][right]-pre[len-1][left-1]+mod)%mod;
    				// dp[len][end]%=mod;
    			}
    		}
    	}

    	ll ans=0;
    	rep(i,1,n)
    	{
    		ans+=dp[n][i];
    		ans%=mod;
    	}
    	cout<<ans;


    }
    	return 0;
    
}
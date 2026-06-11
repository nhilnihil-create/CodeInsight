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

ll matrix[22][22];
ll dp[5000000];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tests=1;
    // compute();
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,n;
    	cin>>n;
    	rep(i,0,n-1)
    	{
    		rep(j,0,n-1)
    		cin>>matrix[i][j];
    	}

    	dp[0]=1;
    	rep(mask,0,(1LL<<n)-2)
    	{
    		ll a=__builtin_popcount(mask);
    		rep(b,0,n-1)
    		{
    			if(matrix[a][b]==1 && !(mask & (1LL<<b)))
    			{
    				// ll mask2=(mask^(1<<j))
    				dp[mask ^ (1<<b)]+=dp[mask];
    				dp[mask ^ (1<<b)]%=MOD;
    			}
    		}
    	}

    	cout<<dp[(1<<n)-1];

    }
    	return 0;
    
}
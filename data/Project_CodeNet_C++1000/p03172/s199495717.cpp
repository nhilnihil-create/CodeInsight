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

ll dp[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {
    	ll x,i,j,n,k;
    	cin>>n>>k;
    // 	vector<ll>pre;
    	dp[0]=1;
    	rep(i,1,n)
    	{
    		cin>>x;
    // 		vector<ll>pre(k+1,0);
            // pre.resize(k+1,0LL);
            ll pre[k+50LL];
            memset(pre,0,sizeof(pre));
    		for(j=0;j<=k;j++)
    		{
    			ll left=j+1;
    			ll right=j+x;
    			if(right>=left)
    			{
    				pre[left]+=dp[j];
    				pre[left]%=MOD;
    				if(right+1<=k)
    					{
    						pre[right+1]-=dp[j];
    						pre[right+1]=(pre[right+1]+MOD)%MOD;
    					}
    			}
    		}
    		rep(j,1,k)
    		{
    			pre[j]+=pre[j-1];
    			pre[j]=(pre[j]+MOD)%MOD;
    			dp[j]+=pre[j];
    			dp[j]=(dp[j]+MOD)%MOD;
    		}

    	}
    	cout<<dp[k];


    }
    	return 0;
    
}
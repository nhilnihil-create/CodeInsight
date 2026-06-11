#include<bits/stdc++.h>
#define ll long long int
#define mk make_pair
#define pb push_back
#define INF (ll)1e18
#define pii pair<ll,ll>
#define mod 1000000007 //998244353
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fb(i,a,b) for(ll i=a;i>b;i--)
#define ff first
#define ss second
#define PI 3.141592653589793238
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>()>
using namespace std;
ll pow_mod(ll a,ll b)
{
	ll res=1;
	while(b!=0)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}
void solve()
{
    vector<ll>v;
    
    ll res=6;
    
    v.pb(1LL);
    
    while(res<=100000)
    {
        v.pb(res);
        res*=6;
    }
    
    res=9;
    
    while(res<=100000){
        v.pb(res);
        res*=9;
    }
    
    ll n=(ll)v.size();
    
    ll dp[100001][n+1];
    
    for(ll i=0;i<100001;i++){
        for(ll j=0;j<=n;j++)
        dp[i][j]=INF;
    }
    
    dp[0][0]=0;
    
    
    for(ll i=0;i<=n;i++)
    dp[0][i]=0;
    
    
    for(ll i=1;i<=n;i++){
        for(ll sum=1;sum<=100000;sum++){
            
            
            if(i>0)
            dp[sum][i]=min(dp[sum][i],dp[sum][i-1]);
            
            if(sum>=v[i-1])
            dp[sum][i]=min(dp[sum][i],1+dp[sum-v[i-1]][i]);
        }
    }
    
    
    ll x;
    cin>>x;
    cout<<dp[x][n]<<endl;
}
int32_t main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
//Start from Here.

  ll t;
  t=1;
 // cin>>t;
  while(t--)
  solve();
  
//Good Bye!
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long int ull;
#define endl "\n"
#define pb push_back
#define sq(a) (a)*(a)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define MOD 1000000007
#define PI 3.141592653589793238
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll exp(ll x,ll n,ll mod)
{
    ll result=1;
    while(n)
    {
        if(n & 1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return result;
}

const ll M=1e9+7;

int32_t main()
{
    IOS

    ll n;
    cin>>n;
    bool mat[n][n];
    for(ll i=0;i<n;i++)
    	for(ll j=0;j<n;j++)
    		cin>>mat[i][j];
    
    vector<ll> dp((1LL<<n),0);
    dp[0]=1;
    
    for(ll mask=1;mask < (1<<n);mask++)
    {
        ll id=__builtin_popcountll(mask);

        for(ll i=0;i<n;i++)
        {
        	if(((mask>>i) & 1) && mat[id-1][i])
        		dp[mask]=(dp[mask] + dp[mask^(1LL<<i)])%M;
        }
    }

    ll ans=dp[(1LL<<n)-1];
    cout<<ans<<endl;

    return 0;
}
#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define N         100005
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll xo(ll x, ll y) 
{ 
   return (x | y) & (~x | ~y); 
}  
ll bin_Expo(ll x,ll n)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return bin_Expo(x*x,n/2);
    else                             //n is odd
        return x*bin_Expo(x*x,(n-1)/2);
}
ll mod_Expo(ll x,ll n,ll M)
{
		if(x==0)
		return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mod_Expo((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*mod_Expo((x*x)%M,(n-1)/2,M))%M;
 
}
ll NcR(int n, int r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m=__gcd(p, k); 
            p /= m; 
            k /= m; 
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
}
bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (ll i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
    
}
ll logg(ll base,ll x)
{
    return (ll)(log(x)/log(base));
} 
ll n,a[17][17]; vector<ll> dp(1<<17,0),dd(1<<17,-1);
ll maxi(ll p,ll q,ll r,ll s,ll t,ll u)
{
	return max(p,max(q,max(r,max(s,max(t,u)))));
}
ll count(ll x)
{
	ll m=0;
	if(x==0)
	return dd[0]=0;
	if(x==1)
	return dd[1]=dp[1];
	if(dd[x]!=-1)
	return dd[x];
	rep(i,1,x)
	{
	    ll aa=count(i);
	    ll bb=count(x-i);
		m=maxi(m,dp[i]+dp[x-i],dp[i]+bb,dp[x-i]+aa,aa+bb,dp[x]);
	}
	return dd[x]=m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<setprecision(12)<<fixed;
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll i,j,l,m,first,last,x,k;
    	cin>>n;
    	rep(i,0,n)
    	{
    		rep(j,0,n)
    		{
    			cin>>a[i][j];
			}
		}
		rep(mask,1,1<<n)
		{
			rep(i,0,n)
			{
				if(mask & 1<<i)
				{
					rep(j,i+1,n)
					{
						if(mask & 1<<j)
						dp[mask]+=a[i][j];
					}
				}
			}
		}
		rep(mask,1,1<<n)
		{
			for(j=mask;j>0;j=(j-1)&mask)
			dp[mask]=max(dp[mask],dp[j]+dp[mask^j]);
		}
 		cout<<dp[(1<<n)-1];
	}
	return 0;
}
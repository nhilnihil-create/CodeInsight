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
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define xx          exit(0);
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
ll logg(ll base,ll x) {
    return (ll)(log(x) / log(base));
}
ll dp[1<<17], pre[1<<17];
//rec(0,notPresent,dp[mask],mask,0);
void rec(ll i, vector<ll> &notPresent,ll score_so_far,ll mask,ll group)
{
	if(i==(ll)notPresent.size())
	{
		dp[mask]=max(dp[mask],score_so_far+pre[group]);
		return ;
	}
	rec(i+1,notPresent,score_so_far,mask,group);
	rec(i+1,notPresent,score_so_far,mask^(1<<notPresent[i]),group^(1<<notPresent[i]));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll k,i,j,w,n,m,mask,N;
    	cin>>n;
    	ll a[n][n];
    	rep(i,0,n){
    		rep(j,0,n) cin>>a[i][j];
		}
    	rep(mask,0,1<<n)
    	{
    		pre[mask]=0;
    		rep(i,0,n)
    		{
    			if(mask & (1<<i))
    			{
    				rep(j,0,n)
    				{
    					if((mask^(1<<i)) & (1<<j))
    					pre[mask]+=a[i][j];
					}
				}
			}
			pre[mask]/=2;
		}
		vector<ll> notPresent;
		dp[0]=0;
    	rep(mask,0,1<<n)
    	{
    		notPresent.clear();
    		rep(i,0,n)
    		{
    			if(!(mask & (1<<i)))
    			notPresent.pb(i);
			}
			rec(0,notPresent,dp[mask],mask,0);
		}
    	cout<<dp[(1<<n)-1];
	}
	return 0;
}
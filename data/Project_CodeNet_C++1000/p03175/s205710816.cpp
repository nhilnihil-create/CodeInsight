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
vec v[100005]; ll dp1[100005],dp2[100005];
void dfs(ll x, ll p)
{
	ll y,z;
	y=v[x].size();
	rep(i,0,y)
	{
		z=v[x][i];
		if(z!=p)
		{
			dfs(z,x);
			dp1[x] = (dp1[x]*dp2[z])%mod;
			dp2[x] = (dp2[x]*((dp1[z]+dp2[z])%mod))%mod;
		}
	}
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
    	ll n,k,i,j,m,h,w;
    	cin>>n;
    	repi(i,1,n-1)
    	{
    		cin>>h>>w;
    		v[h].pb(w);
    		v[w].pb(h);
		}
		repi(i,1,n){
			dp1[i]=1;
			dp2[i]=1;
		}
		dfs(1,0);
		cout<<(dp1[1]+dp2[1])%mod;
	}
	return 0;
}











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
ll a[200005], h[200005], dp[200005], tree[400005];
void build()
{
	repi(i,0,400005) tree[i]=0;
}
ll query(ll node, ll st, ll ed, ll l, ll r)
{
	if(st>r || ed<l) return -1*mod;
	if(st>=l && ed<=r) return tree[node];
	ll mid=(st+ed)/2;
	return max(query(2*node+1,st,mid,l,r),query(2*node+2,mid+1,ed,l,r));
}
void update(ll node, ll st, ll ed, ll idx, ll val)
{
	if(st==ed) tree[node]=val;
	else{
		ll mid=(st+ed)/2;
		if(idx>=st && idx<=mid) update(2*node+1,st,mid,idx,val);
		else update(2*node+2,mid+1,ed,idx,val);
		tree[node] = max(tree[2*node+1],tree[2*node+2]);
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
    	ll n,k,i,j,m,w;
    	cin>>n;
    	build();
    	rep(i,0,n) cin>>h[i];
    	rep(i,0,n) cin>>a[i];
    	repi(i,0,200000) dp[i]=0;
		m=0;
    	rep(i,0,n)
    	{
			m = query(0,0,n,0,h[i]-1);
			dp[h[i]] = m + a[i];
			update(0,0,n,h[i],dp[h[i]]);
		}
		repi(i,0,200000) m=max(m,dp[i]);
		cout<<m;
	}
	return 0;
}











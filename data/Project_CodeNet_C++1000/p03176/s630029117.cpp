#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pi 3.1415926535897
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000000
#define inf1 1000000000
#define endl '\n'
ll height[200005];
ll beauty[200005];
ll segtree[900000];
ll query(ll v,ll tl,ll tr,ll l,ll r)
{
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return segtree[v];
	else
	{
		ll tm=(tl+tr)/2;
		ll a=query(2*v,tl,tm,l,min(r,tm));
		ll b=query(2*v+1,tm+1,tr,max(l,tm+1),r);
		return max(a,b);
	}
}
void update(ll v,ll tl,ll tr,ll pos,ll val)
{
	if(tl==tr)
	{
		segtree[v]=val;
		return;
	}
	else
	{
		ll tm=(tl+tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,val);
		else
			update(2*v+1,tm+1,tr,pos,val);
		segtree[v]=max(segtree[2*v],segtree[2*v+1]);
		return;
	}
}
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>height[i];
	for(ll i=1;i<=n;i++)
		cin>>beauty[i];
	for(ll i=1;i<=n;i++)
	{
		ll a=query(1,1,n,1,height[i]-1);
		update(1,1,n,height[i],a+beauty[i]);
	}
	cout<<segtree[1]<<endl;
	return 0;
}
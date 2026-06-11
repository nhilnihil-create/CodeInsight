#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define setpr(pp) fixed<<setprecision(pp)
#define FOR(I,N) for(I=0;I<N;++I)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod	%1000000007
#define pi 3.141592653
#define MX 1000000007
ll ftree[200005];

ll query(ll x)
{
	ll ans = 0;
	for(;x>0;x-=(x&-x))
	{
		ans = max(ans,ftree[x]);
	}
	return ans;
}

void update(ll x,ll delta,ll n )
{
	for(;x<=n;x+=(x&-x))
		ftree[x] = max(ftree[x],delta);
}

int main()
{
	IOS;
	ll n,i,x;
	cin>>n;
	ll h[n+1],a[n+1];
	MS0(ftree);
	ll ans=0;
	for(i=1;i<=n;++i)
		cin>>h[i];
	for(i=1;i<=n;++i)
	{
		cin>>a[i];
		ans = max(ans,a[i]);
	}
	for(i=1;i<=n;++i)
	{
		x = query(h[i]-1);
		x += a[i];
		ans = max(ans,x);
		update(h[i],x,n);
	}
	cout<<ans;
}
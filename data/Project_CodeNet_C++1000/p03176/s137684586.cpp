#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=200001;
ll bit[N+2];

ll query(ll i)
{
	ll mx=0;
	while(i>0)
	{
		mx=max(bit[i],mx);
		i-=i&(-i);
	}
	return(mx);
}
void update(ll i,ll val)
{
	while(i<=N)
	{
		bit[i]=max(val,bit[i]);
		i+=(i&(-i));
	}
}
int main()
{
	ll n;
	cin>>n;
	ll i;
	ll a[n+1]={0};
	ll h[n+1]={0};
	memset(bit,0,sizeof(bit));
	for(i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	map<ll,pair<ll,ll> >mp;
	for(i=1;i<=n;i++)
	{
		mp[h[i]]=make_pair(a[i],i);
	}
	sort(h,h+n+1);
	ll ans=INT_MIN;
	for(i=1;i<=n;i++)
	{
		ll p=mp[h[i]].second;
		ll x=query(p-1);
		ans=max(x+mp[h[i]].first,ans);
		update(p,x+mp[h[i]].first);
	}
	cout<<ans<<"\n";
}
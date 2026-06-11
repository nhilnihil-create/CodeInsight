
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5+5;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    2019;
ll n;ll lo=1;ll hi=2e5;
ll arr[N];
bool fn(ll x)
{
	ll t;
	map<ll,ll> mp;
	if(x==1)
	{
		for(int i=2;i<=n;i++)
		if(arr[i]<=arr[i-1]) return 0;
		return 1;
	}
	for(int i=2;i<=n;i++)
	if(arr[i]<=arr[i-1])
	{
		t=arr[i];
		mp.erase(mp.upper_bound(t),mp.end());

  while(t>0&&mp[t]==x-1)
		{
			mp.erase(t);
			t--;
		}
		if(!t)
		return 0;
		else
		mp[t]++;
	}
	return 1;
}
int main()
{  fast
cin>>n;
//int ans=1;
for(int i=1;i<=n;i++)cin>>arr[i];
while(lo<=hi)
{
	ll mid=(lo+hi)/2;
//	cout<<mid<<endl;
	if(fn(mid))
	hi=mid-1;
	else
	lo=mid+1;
}
cout<<hi+1<<endl;
}

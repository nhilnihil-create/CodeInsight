#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<pair<ll,ll> , null_type,less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M=1e5+5;
ll a[M],b[M];
ll sm[M],eq[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	ll l=1,r=n,m,p=-1;
	ll tot=(n*(n+1))/2;
	tot=tot/2+1;
	while(l<r)
	{
		m=(l+r)/2;
		if(m==p)
			m++;
		p=m;
		ll x=b[p];
		for(ll i=1;i<=n;i++)
		{
			sm[i]=sm[i-1];
			if(a[i]<x)
				sm[i]++;
		}
		ordered_set od,ev;
		ll c=0;
		for(ll i=0;i<=n;i++)
		{
			if(i%2==0)
			{
				c+=ev.order_of_key({sm[i]-i/2,-1});
				c+=od.order_of_key({sm[i]-i/2,-1});
				ev.insert({sm[i]-i/2,i});
			}
			else
			{
				c+=ev.order_of_key({sm[i]-i/2,-1});
				c+=od.order_of_key({sm[i]-(i+1)/2,-1});
				od.insert({sm[i]-(i+1)/2,i});
			}
		}
		// cout<<m<<" "<<c<<endl;
		if(c>=tot)
			r=m-1;
		else
			l=m;
	}	
	cout<<b[l]<<"\n";
	return 0;
}
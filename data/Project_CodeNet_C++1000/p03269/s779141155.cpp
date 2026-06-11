#include <bits/stdc++.h>
using namespace std;
#define ll int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll pw[22];
std::vector<pair<ll,ll> > vtr[22];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll L;
	cin>>L;
	std::vector<ll> v;
	pw[0]=1;
	for(ll i=1;i<=20;i++)
		pw[i]=2*pw[i-1];
	ll z=L;
	while(z)
	{
		v.pb(z%2);
		z/=2;
	}
	ll tot = sz(v);
	ll m=0;
	for(ll i=tot;i>1;i--)
	{
		vtr[i-1].pb({i,pw[tot-i]});
		vtr[i-1].pb({i,0});
		m+=2;
	}
	ll csum = 0;
	for(ll i=sz(v)-1;i>=0;i--)
	{
		if(v[i]==1 && csum)
		{
			vtr[1].pb({tot-i,csum});
			m++;
		}
		if(v[i])
			csum+=pw[i];
	}
	cout<<tot<<" "<<m<<"\n";
	for(ll i=1;i<=tot;i++)
		for(auto u:vtr[i])
			cout<<i<<" "<<u.ff<<" "<<u.ss<<"\n";
	return 0;
}
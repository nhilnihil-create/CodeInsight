#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int M = 1002;
ll a[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<ll> v;
	for(int i=1;i<=n;i++)
	{
		ll s = 0;
		for(int j=i;j<=n;j++)
		{
			s += a[j];
			v.pb(s);
		}
	}
	ll mask = 0;
	for(int i=50;i>=0;i--)
	{
		ll c = (mask|(1LL<<i));
		int z = 0;
		for(auto u:v)
		{
			if((u&c) == c)
				z++;
		}
		if(z>=k)
			mask = c;
	}
	cout<<mask<<"\n";
	return 0;
}
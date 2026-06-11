#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ll> vec;
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	int ptr=0;
	vector<ii> a;
	for(int i=0;i<m;i++)
	{
		ll x,y; cin>>x>>y;
		a.pb({y,x});
	}
	sort(a.rbegin(),a.rend());
	int ptr2=0;
	while(ptr<n&&ptr2<m)
	{
		if(a[ptr2].se<=0) 
		{
			ptr2++; continue;
		}
		if(vec[ptr]>=a[ptr2].fi)
		{
			ptr++; continue;
		}
		a[ptr2].se--;
		vec[ptr]=a[ptr2].fi;
		ptr++;
	}
	ll ans=0;
	for(ll x:vec) ans+=x;
	cout<<ans<<'\n';
}

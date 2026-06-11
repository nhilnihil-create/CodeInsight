#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string ans[1111];
map<ii,char> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	ll sum = 0; 
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y; vec.pb(mp(x,y)); sum=(x+y)%2;
		if(sum<0) sum+=2;
	}
	for(int i=0;i<n;i++)
	{
		ll s2 = (vec[i].fi+vec[i].se)%2;
		if(s2<0) s2+=2;
		if(s2!=sum){cout<<-1<<'\n'; return 0;}
	}
	vector<ll> res;
	ma[mp(1,0)] = 'L'; ma[mp(-1,0)] = 'R';
	ma[mp(0,1)] = 'D'; ma[mp(0,-1)] = 'U';
	if(sum==0)
	{
		res.pb(1);
		for(int i=0;i<n;i++)
		{
			vec[i].fi++;
			ans[i]+='L';
		}
	}
	for(int bit=31;bit>=0;bit--)
	{
		ll mod = (1LL<<bit);
		res.pb(mod);
		for(int i=0;i<n;i++)
		{
			ll x = vec[i].fi; ll y = vec[i].se;
			for(auto d:ma)
			{
				if(ans[i].length()==res.size()) break;
				ll x2 = x+d.fi.fi*mod; ll y2 = y+d.fi.se*mod;
				ll M = mod-1;
				if(abs(x2+y2)<=M&&abs(x2-y2)<=M)
				{
					ans[i]+=d.se; vec[i].fi=x2; vec[i].se=y2;
				}
			}
		}
	}
	cout<<res.size()<<'\n';
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i];
		if(i+1<res.size()) cout<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<'\n';
	}
}

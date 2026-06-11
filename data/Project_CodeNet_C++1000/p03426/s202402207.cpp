#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000
#define pll pair<long,long>
#define se second
#define fi first
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;

pllordered_set s;

ll d;
ll dp[90005];
map<ll,pair<ll,ll> > m;
ll f(ll i)
{
	if(i<=0)
		return 0;
	if(dp[i]!=-1)
		return dp[i];
	ll ans=0;
	if(i-d<=0)
		ans=0;
	else
		ans=(abs(m[i].se-m[i-d].se)+abs(m[i].fi-m[i-d].fi));
	ans+=f(i-d);
	return dp[i]=ans;
}
int main()
{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			ll h,w;
			cin>>h>>w>>d;
			for(ll i=1;i<=h;i++)
			{
				for(ll j=1;j<=w;j++)
				{
					ll val;
					cin>>val;
					m[val]={i,j};
					dp[val]=-1;
				}
			}
			ll q;
			cin>>q;
			while(q)
			{
				q--;
				ll l,r;
				cin>>l>>r;
				//cout<<f(r)<<endl;
				cout<<f(r)-f(l)<<endl;
			}
}

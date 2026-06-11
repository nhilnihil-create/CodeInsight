#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000
#define mod 1000000007
#define pll pair<long,long>
#define se second
#define fi first
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update>pllordered_set;

set<pair<ll,ll> > s;
vector<ll> g[10005];
vector<ll> deg(10005);

int main()
{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			ll n;
			cin>>n;
			vector<pll> edge;
			for(ll i=1;i<n;i++)
			{
				ll x,y;
				cin>>x>>y;
				edge.pb({x,y});
				g[x].pb(y);
				g[y].pb(x);
				deg[x]++;
				deg[y]++;
			}
			vector<ll> c(n);
			for(ll i=0;i<n;i++)
			{
				cin>>c[i];
			}
			for(ll i=1;i<=n;i++)
			{
				s.insert({deg[i],i});
			}
			sort(c.begin(),c.end());
			ll idx=0;
			vector<ll> ans(10005,0);
			vector<ll> vis(10005,0);
			ll res=0;
			while(!s.empty())
			{
				pll x=*s.begin();
				ans[x.se]=c[idx];
				vis[x.se]=1;
				idx++;
				s.erase(s.find({deg[x.se],x.se}));
				for(auto i:g[x.se])
				{
					if(!vis[i]){
						s.erase(s.find({deg[i],i}));
						deg[i]--;
						s.insert({deg[i],i});
					}
					
				} 
				
			}
			for(auto i:edge)
			{
				res+=min(ans[i.fi],ans[i.se]);
			}
			cout<<res<<endl;
			for(ll i=1;i<=n;i++)
				cout<<ans[i]<<" ";
			
			
			
}

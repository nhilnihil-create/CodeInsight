#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
vector<ll> g[200050];
ll ans=0;

ll dfs(ll s,ll par)
{
	ll res1=1,res=1;
	
	vector<ll> v;
	
	for(auto i:g[s])
	{
		if(i==par)
			continue;
		v.pb(dfs(i,s));
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v.size()>0)
		res1+=v[0];
	res=res1;
	if(v.size()>1)
	{
		res1+=v[1];
	}
	ans=max(ans,res1);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
				
	ll n;
	cin>>n;
	
	for(ll i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	
	if(ans%3==2)
		cout<<"Second";
	else
		cout<<"First";
}

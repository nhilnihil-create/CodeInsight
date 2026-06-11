#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int 
#define ar array

const int mxn=1e5+1;
int n;
vector<int> adj[mxn];
bool vis[mxn+1];
const int mod=1e9+7;

pair<ll,ll> dfs(int node)
{
	ll all_white=1;
	ll is_black=0;
	vis[node]=true;
	for(auto i:adj[node])
	{
		if(!vis[i])
		{
			pair<ll,ll> p=dfs(i);
			ll prev_all_white=all_white;
			all_white=((ll)all_white*p.second)%mod;
			is_black=((prev_all_white*p.first)%mod+(is_black*(p.first+p.second))%mod)%mod;
		}
	}
	return make_pair(all_white,(all_white+is_black));
}
int main()
{
	FAST;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//#endif
	//ll testcase;
	//cin>>testcase;
	//for(ll t=0;t<testcase;t++)
	{
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		pair<ll,ll> p=dfs(1);
		cout<<(p.first+p.second)%mod<<'\n';
		
	}
		
	return 0;
}



























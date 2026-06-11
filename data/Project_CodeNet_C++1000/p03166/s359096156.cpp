#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define Mod 1000000007
using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    // return in;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}
vector<ll> dp;
vector<bool> visited;
vector<vector<int> > g;
vector<int> pos;
void dfs(int v) 
{
	visited[v]=true;
	for (auto to : g[v])
	{
		if(!visited[to]) 
			dfs(to);
		dp[v]=max(dp[v],1+dp[to]);
	}
}

int main()	
{
	#ifdef SANS
		freopen("ongoingin.txt","r",stdin);
		freopen("ongoingout.txt","w",stdout);
	#endif
	fast
	int t=1;
	// cin>>t;
	while(t--)	
	{
		int n,m;
		cin>>n>>m;
		g.resize(n+1);
		dp.resize(n+1,0);
		visited.resize(n+1,0);
		for(int i=0; i<m; i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		for(int i=1; i<=n; i++)
		{
			if(!visited[i])
				dfs(i);
		}
		ll ans=0;
		for(int i=1; i<=n; i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
	#ifdef SANS
		cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
	#endif
}
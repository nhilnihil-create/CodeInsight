#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
// struct OnionFind
// {
// 	vector<int> root;
// 	vector<int> sz;
// 	OnionFind(int n)
// 	{
// 		root = vector<int>(n);
// 		iota(root.begin(),root.end(),0);
// 		sz = vector<int>(n,1);
// 	}
// 	int climb(int u)
// 	{
// 		if(root[u]==u)
// 			return u;
// 		else
// 			return root[u] = climb(root[u]);
// 	}
// 	bool merge(int u, int v)
// 	{
// 		u = climb(u);
// 		v = climb(v);
// 		if(u==v)
// 			return false;
// 		if(!(sz[u] <= sz[v]))
// 			swap(u,v);

// 		root[u] = v;
// 		sz[v] += sz[u];
// 		return true;
// 	}
// };
struct edge
{
	int v, w;
	edge(int v, int w):v(v),w(w){}
};
// struct query
// {
// 	int L, R, D;
// 	query(int L, int R, int D):L(L),R(R),D(D);
// };
const int N = 1e5;
vector<edge> adj[N+1];
bool vis[N+1];
int dist[N+1];
bool stay_the_path(int u, int d)
{
	if(vis[u])
		return dist[u]==d;
	vis[u] = true;
	dist[u] = d;
	for(const edge& e : adj[u])
		if(!stay_the_path(e.v,d+e.w))
			return false;
	return true;
}
bool solve()
{
	//vector<query> to_assert;
	int n, m; cin >> n >> m;
	//OnionFind onion(n);
	for(int i = 0; i < m; i++)
	{
		int L, R, D; cin >> L >> R >> D;
		L--, R--;
		// if(onion.merge(L,R))
		// {
		adj[L].push_back({R,D});
		adj[R].push_back({L,-D});
		// }
		// else
		// 	to_assert.push_back(query(L,R,D));
	}
	memset(vis,false,sizeof vis);
	for(int u = 0; u < n; u++)
		if(!vis[u])
		{
			if(!stay_the_path(u,0))
				return false;
		}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<(solve() ? "Yes" : "No")<<endl;

	cout<<flush;
	return 0;
}
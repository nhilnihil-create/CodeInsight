#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin() x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin() x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

vector<vi> adj;

pi dfs(int node, int par)
{
	pi ret(0, node);
	for(int e:adj[node]){
		if (e==par) continue;
		pi p = dfs(e, node); p.fi++;
		ret = (ret.fi > p.fi) ? ret : p;
	}
	return ret;
}

int Diameter()
{
	pi p = dfs(1, 0);
	pi q = dfs(p.se, 0);
	return q.fi;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin>>n;
	adj.resize(n+1);
	rep(i, n-1){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int L = Diameter();

	if (L % 3 == 1){
		cout << "Second\n";
	}else{
		cout << "First\n";
	}
	
	return 0;
}

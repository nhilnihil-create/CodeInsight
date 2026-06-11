#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const long long mod = 998244353;//200003;786433;1e9 + 7;
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int root;
int dsu[100005];
long long mindis = INF;
long long d[100005], sz[100005], h[100005];
map <long long, int> M; 
vector <pair <int, int> > Edge;
vector <int> Adj[100005];

void DFS(int node, int p = -1)
{
	sz[node] = 1;
	for(auto x : Adj[node])
	{
		if(x == p)
		{
			continue;
		}
		h[x] = h[node] + 1;
		DFS(x, node);
		sz[node] += sz[x];
	}
}

int Root(int node)
{
	return dsu[node] == node ? node : dsu[node] = Root(dsu[node]);
}

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> d[i];
		sz[i] = 1;
		M[d[i]] = i;
		dsu[i] = i;
		if(d[i] < mindis)
		{
			root = i;
			mindis = d[i];
		}
	}
	while(M.size() > 1)
	{
		pair <long long, int> temp = *(prev(M.end()));
		long long realdis = temp.fi - n + sz[temp.se] * 2;
		if(M.count(realdis) == false)
		{
			cout << -1;
			return 0;
		}
		if(Root(temp.se) == Root(M[realdis]))
		{
			cout << -1;
			return 0;
		}
		dsu[Root(temp.se)] = Root(M[realdis]);
		Edge.eb(temp.se, M[realdis]);
		sz[M[realdis]] += sz[temp.se];
		M.erase(temp.fi);
	}
	if(Edge.size() != n - 1 || sz[root] != n)
	{
		cout << "-1";
		return 0;
	}
	for(auto x : Edge)
	{
		Adj[x.fi].eb(x.se);
		Adj[x.se].eb(x.fi);
	}
	DFS(root);
	mindis = 0;
	for(int i = 1; i <= n; i++)
	{
		mindis += h[i];
	}
	if(mindis != d[root])
	{
		cout << "-1";
		return 0;
	}
	for(auto x : Edge)
	{
		cout << x.fi << ' ' << x.se << endl;
	}
}
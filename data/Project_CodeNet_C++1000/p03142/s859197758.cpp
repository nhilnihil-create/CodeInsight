# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0LL)
# define debug(x) cerr<< #x << " = " << x << endl
# define ddebug(x, y) cerr<< #x << " = " << x  << ", " << #y << " = " << y << endl
# define tdebug(x, y, z) cerr<< #x << " = " << x  << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define MP make_pair
# define uop(x, y) pii(min(x, y), max(x, y))

const int MAXN = 100 * 1000 + 10;
vector <int> adj[MAXN], x[MAXN];
int cnt[MAXN], par[MAXN];

void dfs(int v)
{
	for (int u : adj[v])
		cnt[u] --;

	for (int u : adj[v])
		if (!cnt[u])
			x[v].PB(u);

	for (int u : x[v])
	{
		par[u] = v;
		dfs(u);
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		u --, v --;
		adj[u].PB(v);
		cnt[v] ++;
	}

	for (int i = 0; i < n; i ++)
		if (!cnt[i])
		{
			par[i] = -1;
			dfs(i);
			break;
		}

	for (int i = 0; i < n; i ++)
		cout << par[i] + 1 << "\n";


	return 0;
}
 


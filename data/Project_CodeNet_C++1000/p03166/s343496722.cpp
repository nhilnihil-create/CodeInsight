#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define endl "\n"
#define pii pair<int,int>
#define mii map<int,int>
#define int long long int
#define fbo find_by_order
#define ook order_of_key
#define in insert
#define F first
#define S second
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a) for(auto ws: a)cout<<ws<<" "; cout<<endl
#define print1(a,b) for(int ws=0;ws<b;ws++) {cout<<a[ws]<<" ";} cout<<endl
#define all(a) a.begin(), a.end()
#define si set<int>
#define print2(a) for(auto ws: a)cout<<"("<<ws.F<<","<<ws.S<<") "; cout<<endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
const int N = 1e5 + 1;
bool vis[N];
vi g[N];
void init(int n, int e)
{
	for (int i = 0; i <= n; ++i)
	{
		vis[i] = false;
		g[i].clear();
	}
	for (int i = 0; i < e; ++i)
	{
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
	}
}
int longestpathfrom[N];
int dfs(int x)
{
	vis[x] = true;
	int path = 0;
	for (int i = 0; i < g[x].size(); ++i)
	{
		if (!vis[g[x][i]])
		{
			path = max(1 + dfs(g[x][i]), path);
		}
		else
		{
			path = max(1 + longestpathfrom[g[x][i]], path);
		}
	}
	return longestpathfrom[x] = path;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	init(n, m);
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])dfs(i);
	}
	cout << *max_element(longestpathfrom, longestpathfrom + n + 1) << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << setprecision(9) << fixed;
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define fo(i,n)         for(i=0;i<n;i++)
#define Fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 3e5, M = N;
//=======================
vi g[N];
stack<int> top_order;
bool vis[N];
int dist[N];
int dp[N];

void ipgraph(int n, int m) {
	int i, u, v;
	while (m--) {
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
	}
}


void top_sort(int u = 0) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (vis[v]) continue;
		top_sort(v);
	}
	top_order.push(u);
}

int longest_path(int u) {
	vis[u] = 1;
	if (dp[u] != -1) return dp[u];
	int ans = 0;
	for (int v : g[u]) {
		ans = max(ans, 1 + longest_path(v));
	}
	return dp[u] = ans;
}

void solve() {
	int i, j, n, m;
	cin >> n >> m;
	ipgraph(n, m);
	memset(vis, 0, sizeof(vis));
	fo(i, n) {
		if (!vis[i]) {
			top_sort(i);
		}
	}
	memset(dp, -1, sizeof(dp));
	// reverse(top_order.begin(),top_order.end());
	fo(i, n + 1) dist[i] = inf;
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	while (top_order.size() > 0) {
		int t = top_order.top();
		top_order.pop();
		if (!vis[t]) {
			dist[t] = 0;
			ans = max(ans, longest_path(t));
		}
	}
	cout << ans << "\n";
}

int32_t main()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}


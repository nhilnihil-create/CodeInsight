#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int modpow(int x, int n, int m) {
	x %= m;
	int res = 1;
	while(n > 0) {
		if(n & 1)
			res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

vi g[N];
int dp[N][2], sz[N];

void dfs(int v, int p) {
	sz[v] = 1;
	dp[v][0] = 1;
	dp[v][1] = 1;
	for(auto it : g[v]) {
		if(it != p) {
			dfs(it, v);
			sz[v] += sz[it];
			dp[v][0] = dp[v][0] * dp[it][1] % mod;
			dp[v][1] = dp[v][1] * ((dp[it][0] + dp[it][1]) % mod) % mod;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, -1);
	cout << (dp[1][0] + dp[1][1]) % mod;

	return 0;
}
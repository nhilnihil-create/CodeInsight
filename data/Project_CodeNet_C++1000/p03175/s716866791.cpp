#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<ull> vul;
typedef vector<pair<ll, ll>> vpl;
typedef pair<ll, ll> pl;
#define For(i, n) for(ll i = 0; i < n; i++)
#define len(n) (ll)(n).size()
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
vector<vl> g;
vb used;
ll dp[100010][2];
void dfs(ll v) {
	used[v] = true;
	for (ll to : g[v]) {
		if (!used[to]) {
			dfs(to);
			dp[v][0] *= dp[to][1];
			dp[v][0] %= ((ll)1e9 + 7);
			dp[v][1] *= ((dp[to][0] + dp[to][1]) % ((ll)1e9 + 7));
			dp[v][1] %= ((ll)1e9 + 7);
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, a, b;
	cin >> n;
	g.resize(n);
	used.resize(n);
	For(i, n - 1) {
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	For(i, n) {
		dp[i][0] = 1;
		dp[i][1] = 1;
	}
	dfs(0);
	ll ans = dp[0][0] + dp[0][1];
	ans %= ((ll)1e9 + 7);
	cout << ans;
	return 0;
}
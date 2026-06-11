#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
VVI adj;
int n, m;
VI res;
int dfs(int v) {
	if(res[v] == INT_MIN) {
		res[v] = 0;
		for (int u : adj[v]) {
			res[v] = max(res[v],1+dfs(u));
		}
	}
	return res[v];
}
void solve() {
	cin >> n >> m;
	adj.assign(n, VI());
	res.resize(n, INT_MIN);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
	}
	int max_ = 0;
	for(int i = 0; i < n; i++) {
		max_ = max(max_,dfs(i));
	}
	cout << max_;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
const int N = 1e5 + 9, MOD = 1e9 + 7;
vector<int> adj[N];
ll mem[N][2];
void add(int &a, int b) {
	if ((a += b) >= MOD)
		a -= MOD;
}

//color = current color of node
ll solve(int node, int par, bool color) {
	ll &rt = mem[node][color];
	if (~rt)
		return rt;
	rt = 1;
	for (int ch : adj[node])
		if (ch != par)
			rt = (rt * (solve(ch, node, 0) + (color == 0) * solve(ch, node, 1)))
					% MOD;
	return rt;
}

int main() {
	run();
	memset(mem, -1, sizeof(mem));
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (solve(1, -1, 0) + solve(1, -1, 1)) % MOD << endl;
}
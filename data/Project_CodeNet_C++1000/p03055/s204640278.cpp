#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

#define ndl cout << '\n'
#define sz(v) int(v.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define present(a, x) (a.find(x) != a.end())
#define db(x) cout << "> " << #x << " = " \
	<< (x) << '\n'
#define db2(x, y) cout << "> " << #x << " = " \
	<< (x) << ", " << #y << " = " << (y) << '\n'
#define db3(x, y, z) cout << "> " << #x << \
	" = " << (x) << ", " << #y << " = " << \
	(y) << ", " << #z << " = " << (z) << '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef map<int, int> mii;
typedef set<int> si;

const int MX = 2e5 + 5;
int n, ans, win[MX];
vvi adj(MX);

int dfs(int node ,int parent){
	int mxH[] = {-1, -1, -1};
	for (auto& child : adj[node])
		if (child != parent){
			mxH[0] = dfs(child, node) + 1;
			sort(mxH, mxH + 3);
		}
	for (int i = 0; i < 3; ++i)
		mxH[i] = max(mxH[i], 0);
	ans = max(ans, mxH[1] + mxH[2]);
	return mxH[2];
}

int main() {
	ios::sync_with_stdio(false);
	cout.precision(10);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1);
	++ans;
//	db(ans);
	win[1] = 1, win[2] = 0;
	for (int i = 3; i <= ans; ++i)
		win[i] = max(!win[i - 1], !win[i - 2]);
	cout << (win[ans] ? "First" : "Second") << '\n';
	return 0;
}

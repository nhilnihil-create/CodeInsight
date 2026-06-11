#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 96181;

const int N = 2e5 + 20;
vector<int> G[N];
int n;

pie dfs(int v, int p = -1, int d = 0) {
	pie res = MP(d, v);
	for (int u : G[v])
		if (u - p) {
			pie tmp = dfs(u, v, d + 1);
			if (tmp.FF > res.FF)
				res = tmp;
		}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, v, u; i < n - 1; i++) {
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	pie tmp = dfs(1);
//	cout << tmp.FF << ' ' << tmp.SS << endl;
	tmp = dfs(tmp.SS);
//	cout << tmp.FF << endl;
	cout << (tmp.FF % 3 == 1 ? "Second" : "First") << endl;
}


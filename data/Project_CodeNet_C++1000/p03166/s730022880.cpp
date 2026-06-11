#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
	}

	vector<int> dist(n, -1);
	function<int(int)> dfs = [&] (int x) {
		if(dist[x] != -1) return dist[x];
		dist[x] = 0;
		for(auto u : g[x])
			dist[x] = max(dist[x], dfs(u)+1); 
		return dist[x];
	};

	for(int i=0; i<n; i++) if(dist[i] == -1) dfs(i);

	cout << *max_element(dist.begin(), dist.end()) << endl;

	return 0;
}

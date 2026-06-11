#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<int> adj[100001];

pair<int, int> dfs(int node, int parent) {
	long long w{1}, b{1};
	for (int nb : adj[node]) {
		if (nb != parent) {
			pair<int, int> z = dfs(nb, node);
			b *= z.first;
			b %= mod;
			w *= (z.first + z.second);
			w %= mod;
		}
	}
	return {w, b};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	pair<long long, long long> ans = dfs(1, 0);
	cout << (ans.first + ans.second)%mod;
}
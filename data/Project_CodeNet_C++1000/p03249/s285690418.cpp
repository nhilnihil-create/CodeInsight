#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> pii;

const long long MAX_N = 1e5 + 5;
long long n, root;
long long Arr[MAX_N];
long long h[MAX_N];
long long Siz[MAX_N];
long long Mark[MAX_N];
long long par[MAX_N];
unordered_map <long long, long long> Map;
vector <pii> edge;
long long dp_d[MAX_N];
long long dp_u[MAX_N];
vector <long long> child[MAX_N];

bool cmp(long long a, long long b) {
	return Arr[b] < Arr[a];
}

void dfs1(long long v) {
	for (long long i = 0; i < child[v].size(); i++) {
		dfs1(child[v][i]);
		dp_d[v] += dp_d[child[v][i]] + Siz[child[v][i]];
	}
}

void dfs2(long long v, long long val) {
	dp_u[v] = val;
	for (long long i = 0; i < child[v].size(); i++)
		dfs2(child[v][i], dp_d[v] - dp_d[child[v][i]] - Siz[child[v][i]] + dp_u[v] + (n - Siz[child[v][i]]));
}

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> Arr[i];
		Siz[i] = 1;
		h[i] = i;
		Map[Arr[i]] = i;
	}
		
	sort(h, h + n, cmp);
	
	for (long long i = 0; i + 1 < n; i++) {
		long long v = h[i];
		long long tmp = Arr[v] + Siz[v] - (n - Siz[v]);

		if (tmp < 0 || (Map[tmp] == 0 && Arr[0] != tmp)) {
			cout << -1 << "\n";
			return 0;
		}
		
		long long u = Map[tmp];
		/*if (Mark[u]) {
			cout << -1 << "\n";
			return 0;
		}*/
		
		Siz[u] += Siz[v];
		par[v] = u;
		edge.push_back({v, u});
		child[u].push_back(v);
		if (n < 2LL * Siz[v]) {
			cout << -1 << "\n";
			return 0;
		}
		//Mark[v] = true;
	}
	root = h[n - 1];
	dfs1(root);
	//dfs2(root, 0);
	
	for (long long i = root; i < root + 1; i++)
		if (dp_d[i] + dp_u[i] != Arr[i]) {
			cout << -1 << "\n";
			return 0;
		}
	
	for (long long i = 0; i + 1 < n; i++)
		cout << edge[i].first + 1 << " " << edge[i].second + 1 << "\n";
	return 0;
}
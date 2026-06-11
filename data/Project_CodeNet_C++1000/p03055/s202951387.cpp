#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	vector <vector <int> > g(n + 1);

	for(int i = 1; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;

	function < int(int, int) > dfs = [&] (int u, int p) {
		int a = 0, b = 0;
		for(int v : g[u]) {
			if(v != p) {
				int l = dfs(v, u);

				if(l > a) {
					b = a;
					a = l;
				}

				else if(l > b)
					b = l;
			}
		}

		ans = max(ans, a + b + 1);
		return a + 1;
	};

	dfs(1, -1);

	printf(2 - (ans % 3) == 0 ? "Second\n" : "First\n");
	return 0;
}
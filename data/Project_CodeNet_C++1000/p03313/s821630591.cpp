#include <bits/stdc++.h>
using namespace std;

#define MX 262144
int a[MX];
vector<int> res[MX];

int main() {
	int n; scanf("%d", &n); n = 1 << n;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		res[i].push_back(i);
	}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < n; j <<= 1)
			if(i & j) {
				int k = i ^ j;
				for(auto u : res[k]) res[i].push_back(u);
				sort(res[i].begin(), res[i].end(), [&] (int u, int v) {
					return a[u] > a[v] || a[u] == a[v] && u < v;
				});
				res[i].resize(unique(res[i].begin(), res[i].end()) - res[i].begin());
				while(res[i].size() > 2) res[i].pop_back();
			}
	int pre = 0;
	for(int i = 1; i < n; i++) {
		int sum = 0;
		for(auto u : res[i]) sum += a[u];
		pre = max(pre, sum);
		printf("%d\n", pre);
	}
	return 0;
}

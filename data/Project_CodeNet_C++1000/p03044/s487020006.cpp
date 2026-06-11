#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::vector<std::vector<std::pair<int, int> > > hen;
std::vector<bool> res;
void dfs(int i, int prev, int64_t dist = 0) {
	res[i] = dist & 1;
	for (auto j : hen[i]) if (j.first != prev) dfs(j.first, i, dist + j.second);
}

int main() {
	int n = ri();
	hen.resize(n);
	for (int i = 1; i < n; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		int c = ri();
		hen[a].push_back({b, c});
		hen[b].push_back({a, c});
	}
	res.resize(n);
	dfs(0, -1);
	for (auto i : res) printf("%d\n", (int) i);
	
	return 0;
}

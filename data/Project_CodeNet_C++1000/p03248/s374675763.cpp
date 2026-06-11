#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3;
int n;
char s[N];
bool valid() {
	for (int i = 0; i <= n / 2; ++i)
		if (s[i] != s[n - i])
			return false;
	return s[1] == '1';
}
int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	scanf("%s", s + 1);
	s[0] = '0';
	n = strlen(s + 1);
	if (!valid()) {
		puts("-1");
		return 0;
	}
	vector<pair<int, int>> edges;
	edges.emplace_back(1, 2);
	int leaf = 2, prevRoot = 1;
	for (int i = 2; i <= n - 2; ++i) {
		if (s[i] == '1') {
			edges.emplace_back(prevRoot, ++leaf);
			prevRoot = leaf;
		} else {
			edges.emplace_back(prevRoot, ++leaf);
		}
	}
	while (leaf < n)
		edges.emplace_back(prevRoot, ++leaf);
	for (auto p: edges) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
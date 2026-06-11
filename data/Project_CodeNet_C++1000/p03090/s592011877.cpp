#include <bits/stdc++.h>

int n;
std::vector<std::pair<int, int> > ans;
int main() {
	scanf("%d", &n);
	if (n & 1) {
		for (int i = 1; i < n; ++i) {
			ans.emplace_back(i, n);
		}
		--n;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (i + j != n + 1) {
				ans.emplace_back(i, j);
			}
		}
	}
	printf("%d\n", static_cast<int>(ans.size()));
	for (auto p : ans) {
		printf("%d %d\n", p.first, p.second);
	}
}
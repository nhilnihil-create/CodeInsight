#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	struct Block {
		int w;
		int s;
		int val;
	};
	Block blocks[n];
	for (int i = 0; i < n; i++) {
		int w = ri(), s = ri(), val = ri();
		blocks[i] = {w, s, val};
	}
	std::sort(blocks, blocks + n, [] (auto i, auto j) { return i.w + i.s < j.w + j.s; });
	int64_t dp[20001];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = blocks[i].s; j >= 0; j--) {
			int next = j + blocks[i].w;
			if (next <= 20000) dp[next] = std::max(dp[next], dp[j] + blocks[i].val);
		}
	}
	std::cout << *std::max_element(dp, dp + 20001) << std::endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct block_st {
	int weight;
	int solid;
	int val;
};

typedef struct block_st Block;

int cmp(Block a, Block b) {
	return (a.weight+a.solid) < (b.weight+b.solid);
}

int n;
vector<Block> blocks;

ll dp[1005][20005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, s, v;
		cin >> w >> s >> v;
		Block cb = {w, s, v};
		blocks.push_back(cb);
	}
	sort(blocks.begin(), blocks.end(), cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 20000; ++j) {
			dp[i][j] = dp[i-1][j];
			int prw = j-blocks[i-1].weight;
			if (prw >= 0 && prw <= blocks[i-1].solid) {
				dp[i][j] = max(dp[i][j], dp[i-1][prw] + blocks[i-1].val);
			}
		}
	}
	ll res = 0;
	for (int i = 0; i <= 20000; ++i) {
		res = max(res, dp[n][i]);
	}
	cout << res << "\n";
	return 0;
}

/*
	construct the tower from top to bottom
	dp[i][j] = max value with prefix 1..i and sum of weights j
	dp[i][j] = we can
		- take the item i -> dp[i-1][j-weight[i]] + val[i] if (j-weight[i]) <= solid[i]
		- not take the item -> dp[i-1][j]

	max strength is 10^4 so we can iterate only up to that, since all weights are >= 1
*/

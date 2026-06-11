#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const long long INF = 2e18 + 18;

struct Block {
	int weight, solidness, value;
	Block() {;}
	Block(int w, int s, int v) {
		weight = w;
		solidness = s;
		value = v;
	}	
};

bool cmp(Block b1, Block b2) {
	return b1.weight + b1.solidness < b2.weight + b2.solidness;
}

vector<Block> b;
vector<long long> dp;

void solve() {
	int n; cin >> n;
	b.resize(n);
	int maxs = 2e4 + 4;
	for (int i = 0; i < n; i++) {
		int w, s, v;
		cin >> w >> s >> v;
		b[i] = Block(w, s, v);
	}
	sort(b.begin(), b.end(), cmp);
	dp.resize(maxs + 1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int w = min(maxs - b[i].weight, b[i].solidness); w >= 0; w--) {
			dp[w + b[i].weight] = max(dp[w + b[i].weight], dp[w] + b[i].value);
		}
	}
	long long ans = 0;
	for (int i = 0; i <= maxs; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
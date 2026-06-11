#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double EPS = 1e-6;
const int MAX_N = 1e3 + 5;
const int MAX_S = 20123;

struct Block {
	int w, s, v;
	void read() {
		cin >> w >> s >> v;
	}
	bool operator<(const Block& b) const {
		return w + s < b.w + b.s;
	}
};

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	vector<Block> blocks(N);
	for (int i = 0; i < N; ++i) {
		blocks[i].read();
	}
	sort(blocks.begin(), blocks.end());

	vector<ll> dp(MAX_S + 1);
	for (Block b: blocks) {
		for (int w = min(b.s, MAX_S - b.w); w >= 0; --w) {
			dp[w + b.w] = max(dp[w + b.w], dp[w] + b.v);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= MAX_S; ++i) {
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}
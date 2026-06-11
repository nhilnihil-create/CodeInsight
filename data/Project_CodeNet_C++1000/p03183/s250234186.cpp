#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

#ifdef LOCAL
#include "/Users/swad/Desktop/CP/debug.h"
#endif

const int N = int(1e4);

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	int n;
	scanf("%d", &n);

	vector<tuple<int, int, int>> blocks(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &get<1>(blocks[i]), &get<0>(blocks[i]), &get<2>(blocks[i]));
		get<0>(blocks[i]) += get<1>(blocks[i]);
	}

	sort(blocks.begin(), blocks.end());

	vector<ll> dp(N + 1, 0);
	ll ans = 0LL;

	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[get<0>(blocks[i]) - get<1>(blocks[i])] + get<2>(blocks[i]));
		for (int s = min(N, get<0>(blocks[i])); s >= get<1>(blocks[i]); s--) {
			dp[s] = max(dp[s], dp[s - get<1>(blocks[i])] + get<2>(blocks[i]));
		}
		for (int s = get<0>(blocks[i]) + 1; s <= N; s++) {
			dp[s] = max(dp[s], dp[s - 1]);
		}
	}

	printf("%lld\n", ans);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 1010, mxW = 2e4 + 5;
int N;

struct block {
	int weight, solid, value;
};

block a[mxN];
ll dp[mxN][mxW];

bool comp(const block& b1, const block& b2) {
	return (b1.weight + b1.solid < b2.weight + b2.solid);
}

ll rec(int b, int w) {
	if (b == N) {
		return 0;
	}
	ll& ret = dp[b][w];
	if (ret != -1) {
		return ret;
	}
	ret = rec(b + 1, w);
	if (a[b].solid >= w) {
		ret = max(ret, a[b].value + rec(b + 1, w + a[b].weight));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i].weight >> a[i].solid >> a[i].value;
	}
	sort(a, a + N, comp);
	memset(dp, -1, sizeof(dp));
	ll ans = rec(0, 0);
	cout << ans;
	
	return 0;
}

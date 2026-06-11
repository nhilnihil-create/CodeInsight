#include <bits/stdc++.h>
using namespace std;
const long long int N = 200000;
long long int dp[N + 1], h[N + 1], v[N + 1], bit[N + 1];
long long int sgtr[4 * N + 5];
int n;
void update(int s, int e, int node, int i, long long int y) {
	if (i < s || i > e)
		return;
	if (s == e && s == i) {
		sgtr[node] = y;
		return;
	}
	long long int mid = (s + e) / 2;
	if (i <= mid)
		update(s, mid, 2 * node + 1, i, y);
	else
		update(mid + 1, e, 2 * node + 2, i, y);
	sgtr[node] = max(sgtr[2 * node + 1] , sgtr[2 * node + 2]);
	return;
}
long long int query (int s, int e, int node, int i, int j) {
	if (s >= i && e <= j)
		return sgtr[node];
	if (e < i || s > j)
		return -1;
	long long int mid = (s + e) / 2;
	long long int ans1 = query(s, mid, 2 * node + 1, i, j);
	long long int ans2 = query(mid + 1, e, 2 * node + 2, i, j);
	return max(ans1, ans2);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		if (h[i] != 1)
			dp[h[i]] = query(1, n, 0, 1, h[i] - 1);
		dp[h[i]] += v[i];
		update(1, n, 0, h[i], dp[h[i]]);
	}
	long long int ans = 0;
	for ( long long int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
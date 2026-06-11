//#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AC 0
vector<long long> t;
void insert(int x, long long v) {
	for (; x < t.size(); x += x & -x) t[x] = max(t[x], v);
}
long long find(int x) {
	long long ans = 0;
	for (; x; x -= x & -x) ans = max(ans, t[x]);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long mx = 0;
	cin >> n;
	t.resize(4 * n + 1);
	vector<int> a(n + 1);
	vector< pair<int, int> > h(n + 1);
	vector<long long> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i].first;
		h[i].second = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(h.begin(), h.end());
	for (int i = 1; i <= n; i++) {
		dp[i] = find(h[i].second - 1) + a[h[i].second];
		insert(h[i].second, dp[i]);
		mx = max(mx, dp[i]);
	}
	cout << mx << '\n';
	return AC;
}
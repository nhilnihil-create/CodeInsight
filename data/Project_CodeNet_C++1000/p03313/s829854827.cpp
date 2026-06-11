#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int a[N];

vector<int> dp[N];

void insert(vector<int> &lhs, const vector<int> &rhs) {
	for (int x : rhs) lhs.push_back(x);
	sort(lhs.begin(), lhs.end());
	reverse(lhs.begin(), lhs.end());
	lhs.resize(2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; int m = 1 << n;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m; i++) dp[i].push_back(a[i]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (j & (1 << i)) insert(dp[j], dp[j ^ (1 << i)]);
	int ans = 0;
	for (int i = 1; i < m; i++) {
		ans = max(ans, dp[i][0] + dp[i][1]);
		cout << ans << "\n";
	}
	return 0;
}


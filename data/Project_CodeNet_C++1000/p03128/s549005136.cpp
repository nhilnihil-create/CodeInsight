#include <bits/stdc++.h>
using namespace std;

int main() {
	int nums[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	
	vector<int> dp(n + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] == -1) continue;
        for (int j = 0; j < m; j++) {
			if (i + nums[a[j]] <= n) dp[i + nums[a[j]]] = max(dp[i + nums[a[j]]], dp[i] + 1);
		}
	}

	string res = "";
	sort(a.begin(), a.end(), greater<int>());
	while (n > 0){
        for (int i = 0; i < m; i++) {
			if (n - nums[a[i]] >= 0) {
				if (dp[n] == dp[n - nums[a[i]]] + 1) {
					res += '0' + a[i];
					n -= nums[a[i]];
					break;
				}
			}
		}
	}
	
	cout << res << endl;
}

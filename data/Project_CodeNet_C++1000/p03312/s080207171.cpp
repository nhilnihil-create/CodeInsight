#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], mid[2][N];
long long sum[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	sum[n + 1] = sum[n];
	for (int i = 1; i <= n; i++) {
		mid[0][i] = mid[0][i - 1];
		while (mid[0][i] <= n && sum[mid[0][i]] * 2 < sum[i]) mid[0][i]++;
	}
	mid[1][n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		mid[1][i] = mid[1][i + 1];
		while (mid[1][i] >= 1 && (sum[n + 1] - sum[mid[1][i]]) * 2 < (sum[n + 1] - sum[i])) mid[1][i]--;
	}
	long long tot = sum[n + 1];
	for (int i = 2; i < n - 1; i++) {
		auto Max = max(max(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), max(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		auto Min = min(min(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), min(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		tot = min(tot, Max - Min);
		
		mid[0][i]--;
		Max = max(max(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), max(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		Min = min(min(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), min(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		tot = min(tot, Max - Min);
		mid[0][i]++;
		
		mid[1][i]++;
		Max = max(max(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), max(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		Min = min(min(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), min(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		tot = min(tot, Max - Min);
		mid[1][i]--;
		
		mid[0][i]--, mid[1][i]++;
		Max = max(max(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), max(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		Min = min(min(sum[mid[0][i]], sum[i] - sum[mid[0][i]]), min(sum[n + 1] - sum[mid[1][i]], sum[mid[1][i]] - sum[i]));
		tot = min(tot, Max - Min);
		mid[0][i]++, mid[1][i]--;
	}
	
	cout << tot << "\n";
	
	return 0;
}

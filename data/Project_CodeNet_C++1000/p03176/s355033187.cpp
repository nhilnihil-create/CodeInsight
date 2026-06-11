#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	int h[n], a[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int size{1};
	while (size <= n) size *= 2;
	
	vector<long long> dp(n + 1), sgt(2*size);
	for (int i = 0; i < n; i++) {
		int l{size}, r{size + h[i] - 2};
		long long max_value{};
		while (l <= r) {
			if (!(r&1)) max_value = max(max_value, sgt[r--]);
			r /= 2, l /= 2;
		}
		
		dp[h[i]] = max_value + a[i];
		
		int z{size + h[i] - 1};
		sgt[z] = dp[h[i]];
		while (z != 1) {
			sgt[z/2] = max(sgt[z/2], sgt[z]);
			z /= 2;
		}
	}
	
	long long ans{};
	for (int i = 0; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
}
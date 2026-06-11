#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long
				
int32_t main() {
	fast_cin();  

	int n; cin >> n;
	int a[n + 1], sum[n + 5] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] += sum[i - 1] + a[i];
	}
	sum[n + 1] = sum[n];
	int l = 0, r = 3;
	int ans = (int)1e17;
	for (int i = 2; i <= n - 2; i++) {
		int let = sum[i];
		while (l + 1 < i && sum[l] < let / 2) {
			l++;
		}
		if (sum[l] > let / 2) l--;
		vector<int> temp;
		int cur = abs(sum[i] - sum[l] - sum[l]);
		if (sum[l] < (let / 2) && l + 1 < i && abs(sum[i] - sum[l + 1] - sum[l + 1]) < cur) {
			temp.push_back(sum[i] - sum[l + 1]);
			temp.push_back(sum[l + 1]);
			l++;
		} else {
			temp.push_back(sum[i] - sum[l]);
			temp.push_back(sum[l]);
		}
		let = sum[n] - sum[i];
		while (r + 1 < n && sum[r] - sum[i] < let / 2) {
			r++;
		}
		if (sum[r] - sum[i] > let / 2) r--;
		cur = abs(sum[n] - sum[r] - sum[r] + sum[i]);
		if (r + 1 < n && abs(sum[n] - sum[r + 1] - sum[r + 1] + sum[i]) < cur) {
			temp.push_back(sum[n] - sum[r + 1]);
			temp.push_back(sum[r + 1] - sum[i]);
			r++;
		} else {
			temp.push_back(sum[n] - sum[r]);
			temp.push_back(sum[r] - sum[i]);
		}
		sort(temp.begin(), temp.end());
		ans = min(ans, abs(temp[3] - temp[0]));
		// cout << l << " " << i << endl;
		// cout << sum[l] << " " << sum[i] - sum[l] << endl;
		// cout << r << " " << n << endl;
		// cout << sum[r] - sum[i] << " " << sum[n] - sum[r] << endl;
 	
	}
	cout << ans << endl;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int inf = 1000000000000000LL;

int dp[5432];

signed main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v;
	rep(i, n) {
		int p;
		cin >> p;
		dp[i] = inf;
		int count = 0;
		for(int j = i - 1; j >= 0; j--) {
			if(v[j] < p) {
				dp[i] = min(dp[i], dp[j] + count * a + (i - j - 1 - count) * b);
			}
			if(v[j] > p) {
				count++;
			}
		}
		if(count == i) {
			dp[i] = min(dp[i], count * a);
		}
		v.push_back(p);
	}
	int ans = inf;
	int ma = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(ma < v[i]) {
			ans = min(ans, dp[i] + (n - 1 - i) * b);
		}
		ma = max(ma, v[i]);
	}
	cout << ans << endl;
}
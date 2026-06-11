#include<bits/stdc++.h>
#define print(x,n) for(int i=0;i<=n;i++)cout<<x[i]<<" "
using namespace std;

// dp[coins][heads]
double dp[3005];

int main() {
	int n;
	cin >> n;
	vector<double> coins(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0 ; j--) {
			if (i < j) {
				dp[j] = 0;
			}
			else if (i == 1 && j == 1) {
				dp[j] = coins[i - 1];
			}
			else if (i == 1 && j == 0) {
				dp[j] = (1 - coins[i - 1]);
			}
			else {
				double prev = dp[j];
				dp[j] = 0;
				dp[j] += (prev * (1 - coins[i - 1]));
				dp[j] += (j - 1 >= 0) ? dp[j - 1] * coins[i - 1] : 0;
			}
		}
	}

	double ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[i];
	}

	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}

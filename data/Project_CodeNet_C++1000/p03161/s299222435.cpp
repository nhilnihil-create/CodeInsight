#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> h(n+k+1);
	vector<int> dp(n +k+ 1, INT_MAX);

	for (int i = 1; i <= n; i++)
		cin >> h[i];

	dp[1] = 0;

	int min = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (dp[i+j] > dp[i] + abs(h[i] - h[i+j]))
				dp[i+j] = dp[i] + abs(h[i] - h[i+j]);
		}
	}

	cout << dp[n] << endl;

}
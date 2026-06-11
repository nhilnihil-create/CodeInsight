#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin); freopen("output1.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int dp[n] = {};
	for (int i = 0; i < n; i++)
		dp[i] = INT_MAX;
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{

		if (i - 1 >= 0) {
			dp[i] =  dp[i - 1] + abs(arr[i - 1] - arr[i]);
		}
		for (int j = 2; j <= k; j++) {

			if (i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + abs(arr[i - j] - arr[i]));
			}
		}

	}
	cout << dp[n - 1];


}
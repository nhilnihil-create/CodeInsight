#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin); freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
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
		if (i - 2 >= 0) {
			dp[i] = min(dp[i], dp[i - 2] + abs(arr[i - 2] - arr[i]));
		}
		/*for (int i = 0; i < n; ++i)
		{
			/* code
			cout << dp[i] << " ";
		}
		cout << endl;*/
	}
	cout << dp[n - 1];


}
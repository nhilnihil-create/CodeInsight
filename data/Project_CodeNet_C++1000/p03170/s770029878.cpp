#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int dp[k + 1];
	memset(dp, 0 , sizeof(dp));
	for (int i = 1; i <= k; i++)
		for (auto x : a)
			if (x <= i)
				if (dp[i - x] == 0)
					dp[i] = 1;
	cout << (dp[k] == 1 ? "First" : "Second");


	return 0;
}
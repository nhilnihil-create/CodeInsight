#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	if(n <= 1) return 0;
	vector<int> h(n);

	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	vector<int> dp(n, 0);
	for(int i = 1; i < n; i++)
	{
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), (i >= 2) ? dp[i -  2] + abs(h[i] - h[i - 2]) : INT_MAX);
	}
	
	cout << dp[n - 1] << endl;
	
	return 0;
}

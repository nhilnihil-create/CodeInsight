#include<bits/stdc++.h>
#define fasterthanlight ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define int long long
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
#define hi "visited\n" //sasta debugging
using namespace std;

//author::@whohet-->Het Patel
int minCost(int n, int k, int *arr, int *dp)
{
	if (n == 0)
		return INT_MAX;
	if (n == 1)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	int mx = INT_MAX;
	for (int i = 1; i <= k; i++)
	{
		if (n - i >= 1)
			mx = min(mx, minCost(n - i, k, arr, dp) + abs(arr[n] - arr[n - i]));
		else break;
	}
	dp[n] = mx;
	return mx;
}

void solve()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	int ans = minCost(n, k, arr, dp);
	cout << ans << endl;
}

signed main()
{
	fasterthanlight;
	int T; T = 1;
	//cin>>T;
	while (T--)
	{
		solve();
	}

	//cout << "\n\n"<<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
	return 0;
}
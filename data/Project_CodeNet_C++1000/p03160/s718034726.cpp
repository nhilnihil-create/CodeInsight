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
int mincost(int n, int *arr, int *dp)
{
	if (n == 0)
		return INT_MAX;
	if (n == 1)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	int ans = min(mincost(n - 1, arr, dp) + abs(arr[n] - arr[n - 1]), mincost(n - 2, arr, dp) + abs(arr[n] - arr[n - 2]));
	dp[n] = ans;
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	int ans = mincost(n, arr, dp);
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
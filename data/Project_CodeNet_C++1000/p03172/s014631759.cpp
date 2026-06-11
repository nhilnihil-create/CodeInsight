#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)
#define fr(i,a,b)       for(int i = a; i < b; i++)
#define mod				1000000007
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int candies(vi &arr, int n, int k)
{
	int dp[n + 1][k + 1];
	//base case
	for (int j = 0; j <= k; j++)
		dp[1][j] = (j > arr[1]) ? 0 : 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (mod + dp[i][j - 1] + dp[i - 1][j] - ((j - arr[i] - 1 >= 0) ? dp[i - 1][j - arr[i] - 1] : 0)) % mod;
		}
	}
	return dp[n][k];
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vi arr(n + 1);
	fr(i, 1, n + 1)
	cin >> arr[i];
	cout << candies(arr, n, k) << endl;
}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}
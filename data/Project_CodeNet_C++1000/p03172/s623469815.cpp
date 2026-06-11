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
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	FIO();
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);

	for (int i = 1; i < n + 1; i++)
		cin >> a[i];

	vector<vector<int> > dp(n + 1, vector<int> (k + 1, 1));

	for (int i = 1; i < k + 1; i++)
	{
		dp[0][i] = 0;
	}

	dp[0][0] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		vector<int> prefix_sum(k + 1);
		prefix_sum[0] = dp[i - 1][0];

		for (int j = 1; j < k + 1; j++)
		{
			prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % mod;
		}

		for (int j = 0; j < k + 1; j++)
		{
			if (j <= a[i])
				dp[i][j] = prefix_sum[j];
			else
			{
				int exclude_index = j - a[i] - 1;
				dp[i][j] = (prefix_sum[j] - prefix_sum[exclude_index] + mod) % mod;
			}
		}

		prefix_sum.clear();
	}
	cout << dp[n][k] << '\n';
	return 0;
}
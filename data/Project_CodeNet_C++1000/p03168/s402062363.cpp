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
	int n; cin >> n;
	vector<double> a(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	vector<vector<double>>dp(n + 1, vector<double>(n + 1, 0.0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] * (1 - a[i - 1]);
			else
				dp[i][j] = dp[i - 1][j - 1] *  a[i - 1] + dp[i - 1][j] * (1 - a[i - 1]);
		}
	}

	double ans = 0.0;

	for (int i = n; i > n / 2; --i)
		ans = ans + dp[n][i];

	cout << ps(ans, 10) << '\n';

	return 0;
}
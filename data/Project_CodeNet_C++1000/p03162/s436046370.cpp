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

int n;
int a[100005][4];
int dp[100005][4];

int solve(int day, int tasks)
{
	if (day >= n)
	{
		return 0;
	}

	if (dp[day][tasks] != -1)
	{
		return dp[day][tasks];
	}

	int ans = INT_MIN;
	if (tasks == 0)
	{
		ans = max(ans, a[day + 1][1] + solve(day + 1, 1));
		ans = max(ans, a[day + 1][2] + solve(day + 1, 2));
		ans = max(ans, a[day + 1][3] + solve(day + 1, 3));
	}
	else if (tasks == 1)
	{
		ans = max(ans, a[day + 1][2] + solve(day + 1, 2));
		ans = max(ans, a[day + 1][3] + solve(day + 1, 3));
	}
	else if (tasks == 2)
	{
		ans = max(ans, a[day + 1][1] + solve(day + 1, 1));
		ans = max(ans, a[day + 1][3] + solve(day + 1, 3));
	}
	else if (tasks == 3)
	{
		ans = max(ans, a[day + 1][1] + solve(day + 1, 1));
		ans = max(ans, a[day + 1][2] + solve(day + 1, 2));
	}

	return dp[day][tasks] = ans;
}

int32_t main()
{
	FIO();
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << solve(0, 0) << '\n';
	return 0;
}
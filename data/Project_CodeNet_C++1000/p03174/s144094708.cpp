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

int dp[22][(1 << 22)];
int n;
int matching(vector<vi>&arr, int i, int women_subset)
{
	// if all men are paired and if no women left, return 1 else 0
	if (i == n)
		return (women_subset == 0) ? 1 : 0;

	if (dp[i][women_subset] != -1)
		return dp[i][women_subset];

	int ans = 0;
	for (int women = 0; women < n; women++)
	{
		bool avail = (1 << women )& women_subset;
		// if women is available and compatable
		if (avail && arr[i][women])
			ans = (ans + matching(arr, i + 1, women_subset ^ (1 << women))) % mod;
	}
	return dp[i][women_subset] = ans;
}

void solve()
{
	cin >> n;
	vector<vi>arr(n, vi(n));
	fr(i, 0, n)
	fr(j, 0, n)
	cin >> arr[i][j];
	memset(dp, -1, sizeof(dp));
	cout << matching(arr, 0, ((1 << n) - 1 )) << endl;
	return;
}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}
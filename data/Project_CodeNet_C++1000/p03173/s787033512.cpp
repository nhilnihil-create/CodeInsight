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
#define inf 			(1LL<<60)
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int csum[401];
int dp[401][401];
int slimes(vi &arr, int i, int j)
{
	if (i == j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	int min_cost = inf;
	for (int k = i; k < j; k++)
	{
		min_cost = min(min_cost , (csum[j + 1] - csum[i]) + slimes(arr, i, k) + slimes(arr, k + 1, j));
	}
	return dp[i][j] = min_cost;
}

void solve()
{
	int n;
	cin >> n;
	vi arr(n);
	fr(i, 0, n)
	cin >> arr[i];

	csum[0] = 0;
	fr(i, 0, n)
	csum[i + 1] = csum[i] + arr[i];
	memset(dp, -1, sizeof(dp));

	cout << slimes(arr, 0, n - 1) << endl;
	return;

}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}
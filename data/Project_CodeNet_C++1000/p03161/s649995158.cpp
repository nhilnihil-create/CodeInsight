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

int n, k;
vector<int> a(100005);
vector<int> dp(100005, -1);

int solve(int start)
{
	if (start == n - 1)
		return 0;
	if (dp[start] != -1)
		return dp[start];

	int val = INT_MAX;

	for (int i = start + 1; i <= min(n, start + k); i++)
	{
		val = min(val, abs(a[start] - a[i]) + solve(i));
	}

	return dp[start] = val;
}

int32_t main()
{
	FIO();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve(0) << '\n';

	return 0;
}
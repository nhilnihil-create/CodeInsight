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
vector<int> a(100005);
vector<int> dp(100005, -1);

int solve(int start)
{
	if (start == n - 1)
		return 0;
	if (dp[start] != -1)
		return dp[start];

	int op1 = abs(a[start] - a[start + 1]) + solve(start + 1);
	int op2 = (start + 2 >= n) ? INT_MAX : abs(a[start] - a[start + 2]) + solve(start + 2);

	return dp[start] = min(op1, op2);
}

int32_t main()
{
	FIO();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve(0) << '\n';

	return 0;
}
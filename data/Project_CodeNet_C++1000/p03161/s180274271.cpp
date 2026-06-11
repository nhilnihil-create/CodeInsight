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

//Minimum ways to reach n from 1 if we can take i+1,i+2...,i+k steps
//(frog2)Atcoder

int n, k;
int a[100005];
int dp[100005];

int solve(int ind)
{
	if (ind >= n)//No of ways to reach last step when we are at last step
	{
		return 0;
	}
	if (dp[ind] != -1)
	{
		return dp[ind];
	}

	int val;
	for (int i = ind + 1; i <= min(n, ind + k); i++)
	{
		val = min(val, abs(a[ind] - a[i]) + solve(i));
	}

	return dp[ind] = val;
}

int32_t main()
{
	FIO();
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(1) << '\n';
	return 0;
}
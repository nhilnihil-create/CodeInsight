#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = 410, inf = 2e18;
int a[mxn];
int dp[mxn][mxn], n;
bool c[mxn][mxn];

int f(int l, int r)
{
	if(c[l][r])
		return dp[l][r];
	if(l == r)
		dp[l][r] = 0;
	else
	{
		dp[l][r] = inf;
		FOR(k, l, r - 1)
			dp[l][r] = min(dp[l][r], f(l, k) + f(k + 1, r) + a[r] - a[l - 1]);
	}
	c[l][r] = 1;
	return dp[l][r];
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	a[0] = 0;
	FOR(i, 1, n)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	memset(c, 0, sizeof(c));
	cout << f(1, n);

	return 0;
}
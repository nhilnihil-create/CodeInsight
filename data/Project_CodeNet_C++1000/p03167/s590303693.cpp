#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define endl "\n"
#define pii pair<int,int>
#define mii map<int,int>
#define int long long int
#define fbo find_by_order
#define ook order_of_key
#define in insert
#define F first
#define S second
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a) for(auto ws: a)cout<<ws<<" "; cout<<endl
#define print1(a,b) for(int ws=0;ws<b;ws++) {cout<<a[ws]<<" ";} cout<<endl
#define all(a) a.begin(), a.end()
#define si set<int>
#define print2(a) for(auto ws: a)cout<<"("<<ws.F<<","<<ws.S<<") "; cout<<endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
int mod = 1000000007;
int power(int x, unsigned int y)
{
	int res = 1;
	x = x % mod;
	while (y > 0)
	{
		if (y & 1)
			res = (x * res) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}
int n, m;
char a[1001][1001];
void read()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
void solve()
{
	cin >> n >> m;
	read();
	int dp[n][m];
	dp[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (dp[i - 1][0] && a[i][0] == '.')dp[i][0] = 1;
		else dp[i][0] = 0;
	}
	for (int i = 1; i < m; ++i)
	{
		if (dp[0][i - 1] && a[0][i] == '.')dp[0][i] = 1;
		else dp[0][i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i][j] == '.')dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else dp[i][j] = 0;
			dp[i][j] %= mod;
		}
	}
	cout << dp[n - 1][m - 1] << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << setprecision(9) << fixed;
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void d_m_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

char grid[1002][1002];

int power(int n, int x)
{
	if (x == 0)
		return 1;

	int small = power(n, x / 2) % mod;
	small = (small * small) % mod;

	if (1 & x)
		small = (n * small) % mod;

	return small;
}

bool isPowerOfTwo(int n)
{
	return n && (!(n & (n - 1)));
}

int numberOfPaths(int h, int w)
{
	int dp[h + 1][w + 1];
	memset(dp, 0, sizeof dp);

	dp[h][w] = 1;

	for (int i = h; i >= 1; i--)
	{
		for (int j = w; j >= 1; j--)
		{
			if (i == h && j == w)
				continue;
			if (grid[i][j] == '#')
				dp[i][j] = 0;
			else {
				if (i != h)
					dp[i][j] = (dp[i + 1][j] + dp[i][j]) % mod;
				if (j != w)
					dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
			}
		}
	}

	return dp[1][1];
}

double dp[400][400][400];
double solve(int x, int y, int z, int n)
{
	if (x < 0 || y < 0 || z < 0)
		return 0;
	if (x == 0 && y == 0 && z == 0)
		return 0;

	if (dp[x][y][z] > -0.9)
		return dp[x][y][z];

	double exp = n + x * solve(x - 1, y, z, n) + y * solve(x + 1, y - 1, z, n) + z * solve(x, y + 1, z - 1, n);

	return dp[x][y][z] = exp / (x + y + z);
}

int32_t main()
{
	//d_m_c();

	int n;
	cin >> n;

	int a, x = 0, y = 0, z = 0;
	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a == 1)
			x++;
		if (a == 2)
			y++;
		if (a == 3)
			z++;
	}

	cout << fixed << setprecision(10) << solve(x, y, z, n);

	return 0;
}
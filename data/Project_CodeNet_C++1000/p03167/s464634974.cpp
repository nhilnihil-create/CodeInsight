#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// find_by_order(k) returns the iterator to the kth largest element (start from 0)
// order_of_key(k) returns the number of elements in the set which are strictly less than the value k

using namespace std;
using namespace __gnu_pbds;

#define ff              first
#define ss              second
#define all(v)          v.begin(), v.end()
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mem(dp,x)       memset(dp,x,sizeof dp);
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define rightmostbit(x) __builtin_ffsll(x)
#define mod             1000000007
#define inf             1e18
#define pi              3.141592653589793238
#define mk(a,n)         int n;cin>>n;vi a(n);for(int i=0;i<n;i++) cin>>a[i]
#define w(x)            int x; cin>>x; while(x--)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dx2[] = { -1 , -1 , -1, 0 , 0 , 1 , 1 , 1};
int dy2[] = { -1 , 0 , 1 , -1, 1 , -1, 0, 1};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void g_b()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
// .Always initialize dp array
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, CATALAN NUMBER
int32_t main()
{
	g_b();
	int n, m;
	cin >> n >> m;
	char a[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int dp[n][m];
	bool f = 0, f1 = 0;
	if (a[n - 1][m - 1] == '#')
	{
		cout << 0;
		return 0;
	}
	memset(dp, 0, sizeof dp);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == n - 1)
			{
				if (a[i][j] == '#')
				{
					dp[i][j] = 0;
					f = 1;
				}
				else if (!f)
					dp[i][j] = 1;
			}
			else if (j == m - 1)
			{
				if (a[i][j] == '#')
				{
					dp[i][j] = 0;
					f1 = 1;
				}
				else if (!f1)
					dp[i][j] = 1;
			}
			else
			{
				if (a[i][j] == '#')
					dp[i][j] = 0;
				else
					dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
			}
		}
	}

	cout << dp[0][0] % mod;
	return 0;

}
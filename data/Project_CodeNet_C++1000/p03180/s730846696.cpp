#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int      long long int
#define MOD      1000000007
#define pb       push_back
#define pf		 push_front
#define vi       vector<int>
#define mi  	 map<int,int>
#define umi		 unordered_map<int,int>
#define pii      pair<int,int>
#define ff 		 first
#define ss 		 second
#define inf		 1e18
#define case	int t;cin>>t;while(t--)
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int powm(int x, int y, int m = MOD) {
	x = x % m; int res = 1; while (y)
	{if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
int modi(int a, int m = MOD) {return powm(a, m - 2, m);}
void pre()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int sm[100000] = {0}, dp[100000] = {0};
int fn(int mask)
{	if (mask == 0)
		return 0;
	if (dp[mask] != -1)
		return dp[mask];
	dp[mask] = 0;
	for (int i = mask; i != 0; i = ((i - 1)&mask))
		dp[mask] = max(dp[mask], sm[i] + fn(mask ^ i));
	return dp[mask];
}
int32_t main()
{	pre();
	//case
	{	int n;
		cin >> n;
		int a[n][n];
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		for (int i = 0; i < (1 << n); i++)
		{	for (int j = 0; j < n - 1; j++)
			{	for (int k = j + 1; k < n; k++)
					if ((i & (1 << j)) && (i & (1 << k)))
						sm[i] += a[j][k];
			}
		}
		//for (int i = 0; i < 8; i++)
		//	cout << sm[i] << endl;
		int as = fn((1 << n) - 1);
		cout << as << endl;

	}
	return 0;
}
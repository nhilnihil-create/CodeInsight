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
int mx(int BITree[], int index)
{
	int m = 0;
	index = index + 1;
	while (index > 0)
	{
		m = max(m, BITree[index]);
		index -= index & (-index);
	}
	return m;
}
void upd(int BITree[], int n, int index, int val)
{
	index = index + 1;
	while (index <= n)
	{
		BITree[index] = max(BITree[index], val);
		index += index & (-index);
	}
}
int32_t main()
{	pre();
	//case
	{	int n;
		cin >> n;
		int h[n], p[n];
		for (int i = 0; i < n; i++)
			cin >> h[i];
		for (int i = 0; i < n; i++)
			cin >> p[i];
		int bit[n + 2] = {0}, dp[n + 2] = {0}, as = 0;

		for (int i = 0; i < n; i++)
		{	int vl = mx(bit, h[i] - 1);
			dp[i] = p[i] + vl;
			//cout << vl << " " << dp[i] << endl;
			upd(bit, n, h[i], dp[i]);
			as = max(as, dp[i]);
		}
		cout << as << endl;

	}
	return 0;
}
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
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[401][401];
mk(arr, 401, int);
mk(pre, 401, int);

int min_cost(int i, int j)
{
	if (i >= j)
		return dp[i][j] = 0;

	if (dp[i][j] != 0)
		return dp[i][j];

	int cur_cost = pre[j] - pre[i - 1];
	int ans = inf;
	for (int k = i + 1; k <= j; k++)
		ans = min(ans, min_cost(i, k - 1) + min_cost(k, j));

	return dp[i][j] = ans + cur_cost;
}

int32_t main()
{
	FIO;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}

	cout << min_cost(1, n) << endl;

	return 0;
}
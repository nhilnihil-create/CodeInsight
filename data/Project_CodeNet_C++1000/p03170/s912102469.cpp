#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define in              insert
#define pb              push_back
#define mp              make_pair
#define lb              lower_bound
#define ub              upper_bound
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
#define mk(arr,n,type)  type *arr=new type[n]
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	int n, k; cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.in(x);
	}

	int dp[k + 2];
	dp[k + 1] = 0;
	for (int i = k ; i >= 1; i--) {
		int cur = 1;
		for (auto it : s) {
			if (i + it <= k + 1)
				cur *= dp[i + it];
			else
				break;
		}

		dp[i] = !cur;
	}

	if (dp[1])
		cout << "First" << endl;
	else
		cout << "Second" << endl;

	return 0;
}
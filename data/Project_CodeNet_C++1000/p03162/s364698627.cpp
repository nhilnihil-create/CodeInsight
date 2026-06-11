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
struct A {
	int a , b , c;
};
// .Always initialize dp array
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, CATALAN NUMBER
int32_t main()
{
	g_b();
	int n; cin >> n;
	vector<A> v;
	for (int i = 0; i < n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		v.pb({a, b, c});
	}
	int dp[n][3];
	mem(dp, 0);
	dp[0][0] = v[0].a;
	dp[0][1] = v[0].b;
	dp[0][2] = v[0].c;
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = v[i].a + max(dp[i - 1][2], dp[i - 1][1]);
		dp[i][1] = v[i].b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = v[i].c + max(dp[i - 1][0], dp[i - 1][1]);

	}
	int ans = -1;
	for (int i = 0; i < 3; i++) ans = max(ans , dp[n - 1][i]);
	cout << ans;
	return 0;
}
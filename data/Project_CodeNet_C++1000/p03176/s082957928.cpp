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

struct FenwickTree
{
	int N;
	vi tree;

	FenwickTree(int n)
	{
		N = n;
		tree.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while (idx <= N) {
			tree[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while (idx > 0) {
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(l) - pref(r);
	}

	void updateMax(int idx, int val)
	{
		while (idx <= N) {
			tree[idx] = max(tree[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx)
	{
		int ans = -inf;
		while (idx > 0) {
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int32_t main()
{
	FIO;

	int n; cin >> n;
	int h[n + 1], a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	FenwickTree bit(200000);

	int ans = -inf;
	for (int i = 1; i <= n; i++) {
		int m = bit.prefMax(h[i]);
		ans = max(ans, m + a[i]);

		bit.updateMax(h[i], m + a[i]);
	}

	cout << ans << endl;

	return 0;
}
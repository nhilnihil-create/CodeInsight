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
#define sz(a) (int)a.size()

const int mxn = 2e5 + 10, INF = 2e18;
int a[mxn], h[mxn], dp[mxn], n;
int tree[4 * mxn];

int getMax(int qs, int qe, int ss, int se, int si) {
	if(qs > se || qe < ss)
		return -INF;
	if(qs <= ss && qe >= se)
		return tree[si];
	int mid = (ss + se) / 2;
	return max(getMax(qs, qe, ss, mid, 2 * si), getMax(qs, qe, mid + 1, se, 2 * si + 1));
}

void update(int i, int val, int ss, int se, int si) {
	if(i < ss || i > se)
		return;
	if(ss == se) {
		tree[si] = val;
		return;
	}
	int mid = (ss + se) / 2;
	update(i, val, ss, mid, 2 * si);
	update(i, val, mid + 1, se, 2 * si + 1);
	tree[si] = max(tree[2 * si], tree[2 * si + 1]);
}

void segTree(int ss, int se, int si) {
	if(ss == se) {
		tree[si] = dp[ss];
		return;
	}
	int mid = (ss + se) / 2;
	segTree(ss, mid, 2 * si);
	segTree(mid + 1, se, 2 *si + 1);
	tree[si] = max(tree[2 * si], tree[2 * si + 1]);
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
	FOR(i, 1, n) {
		cin >> h[i];
	}
	FOR(i, 1, n) {
		cin >> a[i];
	}
	// dp[i] = maximum sum of beauties if the last flower taken has height 'i'
	memset(dp, 0, sizeof(dp));
	segTree(1, n, 1);
	FOR(flower, 1, n) {
		dp[h[flower]] = a[flower];
		int ans = 0;
		if(h[flower] > 1)
			ans = getMax(1, h[flower] - 1, 1, n, 1);
		dp[h[flower]] += ans;
		update(h[flower], dp[h[flower]], 1, n, 1);
	}
	int ans = 0;
	FOR(i, 1, n) {
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
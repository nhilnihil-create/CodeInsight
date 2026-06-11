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

vector<int> max_dp, t;
const int INF = 2e18;

int getMax(int qs, int qe, int ss, int se, int si) {
	if(qs > se || qe < ss)
		return -INF;
	if(qs <= ss && qe >= se)
		return t[si];
	int mid = (ss + se) / 2;
	return max(getMax(qs, qe, ss, mid, 2 * si), getMax(qs, qe, mid + 1, se, 2 * si + 1));
}

void update(int i, int val, int ss, int se, int si) {
	if(i > se || i < ss)
		return;
	if(ss == se) {
		t[si] = val;
		return;
	}
	int mid = (ss + se) / 2;
	update(i, val, ss, mid, 2 * si);
	update(i, val, mid + 1, se, 2 * si + 1);
	t[si] = max(t[2 * si], t[2 * si + 1]);
}

void segTree(int ss, int se, int si) {
	if(ss == se) {
		t[si] = max_dp[ss];
		return;
	}
	int mid = (ss + se) / 2;
	segTree(ss, mid, 2 * si);
	segTree(mid + 1, se, 2 * si + 1);
	t[si] = max(t[2 * si], t[2 * si + 1]);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> h(n), a(n);
	for(int &x : h)
		cin >> x;
	for(int &x : a)
		cin >> x;

	vector<int> dp(n);
	max_dp.assign(n + 1, 0);
	t.assign(4 * (n + 1), 0);

	max_dp[h[0]] = a[0];
	dp[0] = a[0];

	segTree(1, n, 1);

	for(int i = 1; i < n; i++) {
		dp[i] = a[i];
		int cur = 0;
		if(h[i] > 1) {
			cur = max(cur, getMax(1, h[i] - 1, 1, n, 1));
			// for(int j = 1; j < h[i]; j++) {
			// 	dp[i] = max(dp[i], a[i] + max_dp[j]);
			// }
		}
		dp[i] += cur; 
		max_dp[h[i]] = max(max_dp[h[i]], dp[i]);
		update(h[i], max_dp[h[i]], 1, n, 1);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		// cout << dp[i] << ' ';
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
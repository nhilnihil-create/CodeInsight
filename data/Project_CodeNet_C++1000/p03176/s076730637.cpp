#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

struct segtree {
	int size;
	vector<int> maxs;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		maxs.assign(2*size, 0);
		return;
	}

	void set(int pos, int val, int x, int lx, int rx) {
		if (rx - lx == 1) {
			maxs[x] = val;
			return;
		}
		int mid = (lx + rx) / 2;
		if (pos < mid) set(pos, val, 2*x + 1, lx, mid);
		else set(pos, val, 2*x + 2, mid, rx);
		maxs[x] = max(maxs[2*x + 1], maxs[2*x + 2]);
		return;
	}

	void set(int pos, int val) {
		return set(pos, val, 0, 0, size);
	}

	int calc_max(int l, int r, int x, int lx, int rx) {
		if (l <= lx && rx <= r) {
			return maxs[x];
		}
		if (rx <= l || r <= lx) return 0;
		int mid = (lx + rx) / 2;
		int left_max = calc_max(l, r, 2*x + 1, lx, mid);
		int right_max = calc_max(l, r, 2*x + 2, mid, rx);
		return max(left_max, right_max);
	}

	int calc_max(int l, int r) {
		return calc_max(l, r, 0, 0, size);
	}
};

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	int n;
	cin >> n;
	segtree st;
	vector<int> height(n), beauty(n); int max_height = 0;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		if (height[i] > max_height) max_height = height[i];
	} 
	for (int i = 0; i < n; i++) {
		cin >> beauty[i];
	}
	vector<int> dp(max_height + 1);
	st.init(max_height + 1);
	// dp[i] = max_beauty of flowers where max height is i
	for (int flower = 0; flower < n; flower++) {
		int best_val = st.calc_max(0, height[flower]);
		dp[height[flower]] = beauty[flower] + best_val;
		st.set(height[flower], dp[height[flower]]);
	}
	cout << st.calc_max(0, max_height + 1) << endl;

	return 0;
}
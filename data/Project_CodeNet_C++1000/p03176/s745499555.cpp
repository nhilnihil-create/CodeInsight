#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


// range query using segment tree
#define ISMAXRANGE	1		// 1 = max range, 0 = min range
#define VERYBIG		(1LL << 60)	


class segment_tree {
	vector<long long> t;
	long size;
public:
	segment_tree(long n) {
		if (ISMAXRANGE) t.assign(4 * n + 1, 0);
		else t.assign(4 * n + 1, VERYBIG);
		size = n;
	}

	void initialize_array(vector<long long>& v) {
		initialize_with_array(1, 0, size - 1, v);
	}

	void initialize_with_array(long startpos, long l, long r, vector<long long>& v) {
		if (l == r) {
			t[startpos] = v[l];
		}
		else {
			long m = (l + r) / 2;
			initialize_with_array(2 * startpos, l, m, v);
			initialize_with_array(2 * startpos + 1, m + 1, r, v);

			if (ISMAXRANGE == 1) t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
			else  t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
		}
	}

	void update(long index, long long val) { // insert val into location index
		update_full(1, 0, size - 1, index, val);
	}

	void update_full(long startpos, long l, long r, long index, long long val) {
		if (l == r) {
			t[startpos] = val;
		}
		else {
			long m = (l + r) / 2;
			if (index <= m) update_full(2 * startpos, l, m, index, val);
			else update_full(2 * startpos + 1, m + 1, r, index, val);

			if (ISMAXRANGE) t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
			else t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
		}
	}

	long long query(long l, long r) {  // get range min/max between l and r
		if (l > r) {
			if (ISMAXRANGE) return 0;
			else return VERYBIG;
		}
		return query_full(1, 0, size - 1, l, r);
	}

	long long query_full(long startpos, long left, long right, long l, long r) {	 // left/right = current range, l/r = intended query range
		if ((left >= l) && (right <= r)) return t[startpos];
		long m = (left + right) / 2;
		long long ans;
		if (ISMAXRANGE) ans = -(1LL << 60);
		else ans = VERYBIG;
		if (m >= l) {
			if (ISMAXRANGE) ans = max(ans, query_full(startpos * 2, left, m, l, r));
			else ans = min(ans, query_full(startpos * 2, left, m, l, r));
		}
		if (m + 1 <= r) {
			if (ISMAXRANGE) ans = max(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
			else ans = min(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
		}
		return ans;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, x;
	cin >> n;
	vector<long long> h(n), a(n);
	for (i = 0; i < n; i++) cin >> h[i];
	for (i = 0; i < n; i++) cin >> a[i];

	segment_tree st(n + 10);
	vector<long long> dp(n, 0);

	for (i = 0; i < n; i++) {
		x = st.query(0, h[i]);
		dp[i] = x + a[i];
		st.update(h[i], dp[i]);
	}

	ans = *max_element(dp.begin(), dp.end());

	cout << ans << "\n";


	return 0;
}




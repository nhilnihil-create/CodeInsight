#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;

class SegmentTree {
private:
	int num;
	vector<ll> dat;

	// TODO: Change the operator and the identity element.
	static const ll INI = 0;
	ll op(ll a, ll b) {
		return a + b;
	}

public:
	SegmentTree(int n_) {
		num = 1;
		while (num < n_) num *= 2;
		dat = vector<ll>(2 * num, INI);
	}

	// Update the k-th value (0-indexed) to a.
	void update(int k, ll a) {
		k += num - 1;
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
		}
	}

	// Get the value of the range [a, b).
	// k: The index of the node.
	// [left, right): The range corresponds to the k-th node.
	// Call like getval(a, b).
	ll getval(int a, int b, int k = 0, int left = 0, int right = -1) {
		if (right < 0) right = num;
		if (right <= a || b <= left) return INI;
		if (a <= left && right <= b) return dat[k];
		ll vleft = getval(a, b, 2 * k + 1, left, left + (right - left) / 2);
		ll vright = getval(a, b, 2 * k + 2, left + (right - left) / 2, right);
		return op(vleft, vright);
	}
};


int main() {
	int n; cin >> n;
	vector<ll> a(n), b(n), s(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll lo = 0, hi = 1e9 + 1;
	while (hi - lo > 1) {
		ll mid = lo + (hi - lo) / 2;
		for (int i = 0; i < n; i++) b[i] = a[i] >= mid ? 1 : -1;
		for (int i = 0; i < n; i++) s[i + 1] = s[i] + b[i];
		SegmentTree seg(200005);
		ll cnt = 0;
		for (int i = 0; i <= n; i++) {
			int k = s[i] + 100000;
			cnt += seg.getval(0, k + 1);
			seg.update(k, seg.getval(k, k + 1) + 1);
		}
		if (cnt >= (1LL*n*(n + 1)/2 + 1) / 2) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
	return 0;
}
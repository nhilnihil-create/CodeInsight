#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printArray(arr) for (int i = 0; i<size(arr); i++) cout << arr[i] << " ";cout << '\n'
#define printVerdict(verdict) cout << (verdict ? "YES": "NO") << '\n'
#define printDecimal(d) printf("%.9f\n", d)
#define inrange(val, start, end) (val >= start && val <= end)

const ll inf = 0x3f3f3f3f;

template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) {cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';}
template <class T1, class T2>
void printPair(pair<T1, T2> p) {cout << p.first << " " << p.second << '\n';}

struct segTree {
	int sz; 
	vector<ll> tree;
	void init(ll n) {
		sz = 1;
		while (sz < n) sz *= 2;
		tree.assign(2*sz + 1, 0ll);
	}
	
	void set(int idx, ll val) {set(idx, val, 0, 0, sz);}
	void set(int idx, ll val, int curr, int left, int right) {
		if (right - left == 1) tree[curr] = val;
		else {
			int mid = left + (right - left)/2;
			if (idx < mid) set(idx, val, curr*2+1, left, mid);
			else set(idx, val, curr*2 + 2, mid, right);
			tree[curr] = max(tree[curr*2 + 1], tree[curr*2 + 2]);
		}
	}
	
	ll evaluate(int left, int right) {return evaluate(left, right, 0, 0, sz);}
	ll evaluate(int left, int right, int curr, int curr_left, int curr_right) {
		if (curr_left >= right || left >= curr_right) return 0;
		if (curr_left >= left && curr_right <= right) return tree[curr];
		int mid = curr_left + (curr_right - curr_left)/2;
		ll s1 = evaluate(left, right, curr*2+1, curr_left, mid), s2 = evaluate(left, right, curr*2+2, mid, curr_right);
		return max(s1, s2);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	ll h[n], a[n];
	ll maxHeight = 0;
	for (int i = 0; i<n; i++) {
		cin >> h[i];
		maxHeight = max(maxHeight, h[i]);
	}
	for (int i = 0; i<n; i++) cin >> a[i];
	segTree tree;
	tree.init(maxHeight);
	
	vector<ll> dp(n);
	ll ret = 0;
	for (int i = 0; i<n; i++) {
		ll temp = tree.evaluate(1, h[i]);
		dp[i] = temp + a[i];
		tree.set(h[i], dp[i]);
		ret = max(ret, dp[i]);
	}
	cout << ret << '\n';
	
}


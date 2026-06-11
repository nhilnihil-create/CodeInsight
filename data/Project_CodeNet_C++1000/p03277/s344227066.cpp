#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define MOD 1000000007
int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

struct SegTree {
	std::vector<int> data;
	int n;
	SegTree(int n_) {
		for (n = 1; n < n_; n *= 2);
		data.resize(2 * n);
	}
	int sum(int l, int r) {
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (r & 1) r--, res += data[r];
			if (l & 1) res += data[l], l++;
		}
		return res;
	}
	void add(int i, int val) {
		for (i += n; i; i >>= 1) data[i] += val;
	}
};

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	int l = -1, r = 1000000001;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		int b[n + 1];
		b[0] = n;
		for (int i = 0; i < n; i++) b[i + 1] = b[i] + (a[i] <= m ? 1 : -1);
		SegTree tree(2 * n + 1);
		tree.add(b[0], 1);
		int64_t num = 0;
		for (int i = 1; i <= n; i++) {
			num += tree.sum(0, b[i]);
			tree.add(b[i], 1);
		}
		if (num > (int64_t) n * (n + 1) / 4) r = m;
		else l = m;
	}
	std::cout << r << std::endl;
	return 0;
}


// Problem : D - Equal Cut
// Contest : AtCoder Regular Contest 100
// URL : https://atcoder.jp/contests/arc100/tasks/arc100_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int N = 1e6 + 1, mod = 1e9 + 7;

int n, a[N];
ll ans = LLONG_MAX, psum[N];

ll sum(int l, int r) {
	return psum[r] - psum[l - 1];
}

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = 2; i < n - 1; i++) {
		int posl = 1;
		for (int j = log2(i); j >= 0; j--) {
			posl += 1 << j;
			if (posl >= i || sum(1, posl) > sum(posl + 1, i)) {
				posl -= 1 << j;
			}
		}
		ll ansl = abs(sum(1, posl) - sum(posl + 1, i));
		ll mnl = min(sum(1, posl), sum(posl + 1, i));
		ll mxl = max(sum(1, posl), sum(posl + 1, i));
		if (posl != i - 1) {
			if (ansl > abs(sum(1, posl + 1) - sum(posl + 2, i))) {
				ansl = abs(sum(1, posl + 1) - sum(posl + 2, i));
				mnl = min(sum(1, posl + 1), sum(posl + 2, i));
				mxl = max(sum(1, posl + 1), sum(posl + 2, i));
			}
		}
		int posr = i + 1;
		for (int j = log2(n - i); j >= 0; j--) {
			posr += 1 << j;
			if (posr > n - 1 || sum(i + 1, posr) > sum(posr + 1, n)) {
				posr -= 1 << j;
			}
		}
		ll ansr = abs(sum(i + 1, posr) - sum(posr + 1, n));
		ll mnr = min(sum(i + 1, posr), sum(posr + 1, n));
		ll mxr = max(sum(i + 1, posr), sum(posr + 1, n));
		if (posr != n - 1) {
			if (ansr > abs(sum(i + 1, posr + 1) - sum(posr + 2, n))) {
				ansr = abs(sum(i + 1, posr + 1) - sum(posr + 2, n));
				mnr = min(sum(i + 1, posr + 1), sum(posr + 2, n));
				mxr = max(sum(i + 1, posr + 1), sum(posr + 2, n));
			}
		}
		ans = min(ans, max(mxl, mxr) - min(mnl, mnr));
	}
	cout << ans;
}

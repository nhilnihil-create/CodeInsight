
// Problem : D - Binomial Coefficients
// Contest : AtCoder Regular Contest 095
// URL : https://atcoder.jp/contests/arc095/tasks/arc095_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n, mx = 0, ans = 0, pos, a[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] <= mx / 2) {
			if (ans < a[i]) {
				ans = a[i];
				pos = i;
			}
		} else {
			if (ans < mx - a[i]) {
				ans = mx - a[i];
				pos = i - n;
			}
		}
	}
	cout << mx << ' ' << a[(pos + n) % n];
}

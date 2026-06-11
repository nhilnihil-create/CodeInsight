
// Problem : E - LISDL
// Contest : AtCoder Regular Contest 091
// URL : https://atcoder.jp/contests/arc091/tasks/arc091_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()
#define reverse(l, sz) reverse(c + l, c + l + sz)

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n, a, b, c[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b;
	if (a + b - 1 > n || 1ll * a * b < n) {
		return cout << -1, 0;
	}
	int first = n - n / a * a;
	for (int i = 1; i <= first; i++) {
		c[i] = i + n - first;
	}
	for (int i = 1; i <= n / a; i++) {
		for (int j = 1; j <= a; j++) {
			c[a * (i - 1) + j + first] = j + (n / a - i) * a;
		}
	}
	int need = b - (n / a + !!(n % a));
	if (first >= 1) {
		if (need >= first - 1) {
			reverse(1, first);
			need -= first - 1;
		} else {
			reverse(1, need + 1);
			need = 0;
		}
	}
	for (int i = 1; i < n / a; i++) {
		if (!need) {
			break;
		}
		int f = first + a * (i - 1) + 1;
		if (need >= a - 1) {
			reverse(f, a);
			need -= a - 1;
		} else {
			reverse(f, need + 1);
			need = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << c[i] << ' ';
	}
}


// Problem : D - Two Sequences
// Contest : AtCoder Regular Contest 092
// URL : https://atcoder.jp/contests/arc092/tasks/arc092_b
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define temptts template <class T, class... Ts>

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n, ans = 0, a[N], b[N], cnt[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int k = 28; k >= 0; k--) {
		int x = 1 << k;
		for (int i = 1; i <= n; i++) {
			a[i] %= x << 1;
			b[i] %= x << 1;
		}
		sort(b + 1, b + n + 1);
		int cnt = 0;
		for (int i = 1, l, r; i <= n; i++) {
			r = lower_bound(b + 1, b + n + 1, 2 * x - a[i]) - b;
			l = lower_bound(b + 1, b + n + 1, x - a[i]) - b;
			cnt += r - l;
			r = lower_bound(b + 1, b + n + 1, 4 * x - a[i]) - b;
			l = lower_bound(b + 1, b + n + 1, 3 * x - a[i]) - b;
			cnt += r - l;
		}
		if (cnt & 1) {
			ans += x;
		}
	}
	cout << ans;
}

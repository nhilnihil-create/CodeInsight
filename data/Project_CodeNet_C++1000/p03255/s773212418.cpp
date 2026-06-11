#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, x;
int a[N];
long long sum[N];

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	long long res = (1ll << 60);
	for (int i = 1; i <= n; i++) {
		int r = n;
		int cnt = 0;
		long long foo = 0ll;
		bool isBreak = 0;
		while (r > 0) {
			int l = max(0, r - i);
			cnt++;
			if (cnt == 1) {
				foo += 5ll * (sum[r] - sum[l]);
			} else {
				foo += (2ll * cnt + 1ll) * (sum[r] - sum[l]);
			}
			if (foo > res) {
				isBreak = 1;
				break;
			}
			r = l;
		}
		if (isBreak) {
			continue;
		}
		foo += 1ll * i * x;
		// cout << i << " " << foo << endl;
		res = min(res, foo);
	}
	cout << res + 1ll * n * x << endl;
	return 0;
}
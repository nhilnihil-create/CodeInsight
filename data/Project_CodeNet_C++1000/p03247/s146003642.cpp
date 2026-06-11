#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << (x) << endl
using namespace std;

const int N = 1001, M = 31;

int n, x[N], y[N];

long long my_abs (long long x) {
	return x > 0 ? x : -x;
}
bool check () {
	for (int i = 1; i < n; i++) {
		if (((1ll << M) + x[i] + y[i]) % 2 != ((1ll << M) + x[n] + y[n]) % 2) return false;
	}
	return true;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);

	if (!check()) printf("-1\n");
	else {
		if (((1ll << M) + x[n] + y[n]) % 2 == 0) printf("%d\n1 ", M + 1);
		else printf("%d\n", M);
		for (int i = 0; i < M; i++) printf("%lld ", 1ll << i);
		printf("\n");
		for (int i = 1; i <= n; i++) {
			string ans;
			bool even = (((1ll << M) + x[i] + y[i]) % 2 == 0);
			if (even) x[i]--;

			for (int j = M - 1; j >= 0; j--) {
				long long len = 1ll << j;
				if (my_abs(x[i] - len) + my_abs(y[i]) < len) {
					ans = 'R' + ans;
					x[i] -= len;
				}
				else if (my_abs(x[i] + len) + my_abs(y[i]) < len) {
					ans = 'L' + ans;
					x[i] += len;
				}
				else if (my_abs(x[i]) + my_abs(y[i] - len) < len) {
					ans = 'U' + ans;
					y[i] -= len;
				}
				else if (my_abs(x[i]) + my_abs(y[i] + len) < len) {
					ans = 'D' + ans;
					y[i] += len;
				}
			}

			if (even) ans = 'R' + ans;
			cout << ans << endl;
		}
	}
	return 0;
}
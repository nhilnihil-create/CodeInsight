#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];
long long f[N];

int main() {
	int n, A, B;
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	a[0] = 0;
	a[n + 1] = n + 1;
	f[0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		f[i] = 1e18;
		int cnt = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (a[i] > a[j]) {
				f[i] = min(f[i], f[j] + (long long) A * cnt + (long long) B * (i - j - 1 - cnt));
			} else {
				++cnt;
			}
		}
	}
	printf("%lld\n", f[n + 1]);	
}

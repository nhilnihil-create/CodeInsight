#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;

int a[maxn];
double b[maxn];

int main() {
	int n, maxa = -1;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	sort(a + 1, a + 1 + n);
	double mid = 1.0 * a[n] / 2, m1 = 1000000009.0;

	int ans;

	for (int i = 1; i < n; ++i) {
		if (fabs(mid - (1.0 * a[n] - 1.0 * a[i])) < m1) {
			ans = a[i];
			m1 = fabs(mid - (1.0 * a[n] - 1.0 * a[i]));
		}
	}
    printf("%d %d\n",a[n],ans);

}
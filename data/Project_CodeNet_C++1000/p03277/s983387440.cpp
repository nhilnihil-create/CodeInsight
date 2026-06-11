#include <bits/stdc++.h>

using namespace std;

int f[400001];
int n;
void add(int x) {
	for (; x <= 3 * n; x += (x & -x)) f[x] ++;
}

int query(int x) {
	int sum = 0;
	for (; x; x -= (x & -x)) sum += f[x];
	return sum;
}

int sum[400001], e[400001], c[400001];
int a[400001], b[400001];
bool check(int x) {
	for (int i = 1; i <= n; i ++) {
		if (a[i] >= x) c[i] = 1;
		else c[i] = 0;
		sum[i] = sum[i - 1] + c[i];
		e[i] = 2 * sum[i] - i;
	}
	long long ans = 0;
	for (int i = 1; i <= 3 * n; i ++) f[i] = 0;
	for (int i = 1; i <= n; i ++) {
		add(e[i - 1] + n + 1);
		ans += query(e[i] + n + 1);
	}
	return 2 * ans >= 1LL * n * (n + 1) / 2;
}

int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int m = (int )(unique(b + 1, b + 1 + n) - b) - 1;
	int l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(b[mid])) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", b[r]);
	return 0;
}

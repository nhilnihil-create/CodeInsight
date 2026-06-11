#include <bits/stdc++.h>

using namespace std;

int n, x[100005], y[100005];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x + i, y + i);
	n++;
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 0; x[n - 1 - i] > y[i]; i++)
		ans += x[n - 1 - i] - y[i];
	printf("%lld\n", ans * 2);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, l[maxn + 10], r[maxn + 10];
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	sort(l, l + n + 1, greater<int>());
	sort(r, r + n + 1);
	for (int i = 0; i <= n; ++i)
		ans += 2 * max(l[i] - r[i], 0);
	printf("%lld", ans);
}

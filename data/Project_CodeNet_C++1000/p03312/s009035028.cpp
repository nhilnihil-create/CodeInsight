#include <bits/stdc++.h>
#include <bits/extc++.h>
#define calc(a,b,c,d) max(a, max(b, max(c, d))) - min(a, min(b, min(c, d)))
using namespace std;

int n, a[200010], p[200010], s[200010];
long long ps[200010], ss[200010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		ps[i] = ps[i - 1] + a[i];
	for (int i = n; i >= 1; --i)
		ss[i] = ss[i + 1] + a[i];
	for (int i = 2, j = 1; i <= n - 2; ++i) {
		while (ps[j + 1] << 1 <= ps[i]) ++j;
		p[i] = ps[i] - (ps[j] << 1) < (ps[j + 1] << 1) - ps[i] ? j : j + 1;
	}
	for (int i = n - 1, j = n; i >= 3; --i) {
		while (ss[j - 1] << 1 <= ss[i]) --j;
		s[i] = ss[i] - (ss[j] << 1) < (ss[j - 1] << 1) - ss[i] ? j : j - 1;
	}
	
	long long ans = 200000000000000;
	for (int i = 2; i <= n; ++i)
		ans = min(ans, calc(ps[p[i]], ps[i] - ps[p[i]],
					ss[i + 1] - ss[s[i + 1]], ss[s[i + 1]]));
	printf("%lld\n", ans);
	return 0;
}

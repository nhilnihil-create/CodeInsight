# include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, l[N], r[N], lid[N], rid[N], u[N];
int cmp1(int i, int j) {
	return l[i] != l[j] ? l[i] > l[j] : r[i] > r[j];
}
int cmp2(int i, int j) {
	return r[i] != r[j] ? r[i] < r[j] : l[i] < l[j];
}
int main() {
	// freopen("c.in", "r", stdin);
	scanf("%d", & n);
	for (int i = 1; i <= n; i ++)
		scanf("%d %d", l + i, r + i), lid[i] = rid[i] = i;
	sort(lid + 1, lid + n + 1, cmp1), sort(rid + 1, rid + n + 1, cmp2);
	long long ans = - ~ 0ull >> 2;
	for (int S = 0; S <= 1; S ++) {
		memset(u, 0, sizeof u);
		long long sum = 0;
		int cur = 0;
		for (int dir = S, rc = 0, lc = 0; ; dir ^= 1)
			if (! dir) {
				int id = rid[++ rc];
				if (r[id] >= cur)
					break;
				sum += cur - r[id], cur = r[id];
			}
			else {
				int id = lid[++ lc];
				if (l[id] <= cur)
					break;
				sum += l[id] - cur, cur = l[id];
			}
		sum += abs(cur), ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
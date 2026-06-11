#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

int size[100010], fa[100010];
long long dp[100010];
map <long long, int> to_i;
long long D[100010];
int n;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &D[i]);
		to_i[D[i]] = i;
		size[i] = 1, dp[i] = 0;
	}
	map <long long, int> :: iterator it = to_i.end();
	while ((--it) != to_i.begin()) {
		int x = it->se;
		if (2 * size[x] >= n || !to_i.count(D[x] + 2 * size[x] - n)) {
			printf("-1\n");
			return 0;
		}
		fa[x] = to_i[D[x] + 2 * size[x] - n];
		size[fa[x]] += size[x], dp[fa[x]] += dp[x] + size[x];
	}
	if (to_i.begin()->fi != dp[to_i.begin()->se]) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (fa[i]) printf("%d %d\n", i, fa[i]);
	}
	return 0;
}

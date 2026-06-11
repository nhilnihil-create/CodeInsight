#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000037;
const int maxn = 10004;
const int maxm = 10;

int n, m;
int a[maxm], dp[maxn], p[maxn];
int req[maxm] = {inf, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int rec (int x) {
	if (x < 0) 
		return -inf;
	else if (dp[x] != -1)
		return dp[x];
	else {
		vector < pair < int, int > > to;
		for (int i = 0; i < m; ++i) 
			to.push_back(make_pair(rec(x - req[a[i]]), a[i]));
		sort(to.begin(), to.end());
		if (to.back().first < 0)
			return dp[x] = -inf;
		else {
			p[x] = to.back().second;
			return dp[x] = to.back().first + 1;
		}
	}
}

signed main () {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	rec(n);
	while (n > 0) {
		printf("%d", p[n]);
		n -= req[p[n]];
	}
	printf("\n");
}

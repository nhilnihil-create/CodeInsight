#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
using namespace std;
struct Block {
	int w, s, v;
	bool operator<(Block other) const {
		if (w + s == other.w + other.s) {
			return s > other.s;
		}
		return w + s > other.w + other.s;
	}
};
int n;
Block b[1000];
long long dp[1000][10001];
long long calc(int i, int s) {
	if (i == n) return 0;
	if (dp[i][s] != -1) return dp[i][s];
	long long res = calc(i + 1, s);
	if (b[i].w <= s) {
		res = max(res, calc(i + 1, min(s - b[i].w, b[i].s)) + b[i].v);
	}
	return dp[i][s] = res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d", &b[i].w, &b[i].s, &b[i].v);
	sort(b, b + n);
	memset(dp, -1, sizeof(dp));
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, calc(i + 1, b[i].s) + b[i].v);
	}
	printf("%lld\n", ans);
	return 0;
}
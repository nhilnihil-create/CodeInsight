#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;
const ll INF = 1e18;

int N, A, B;
int perm[MAXN], inv[MAXN];
ll dp[MAXN][MAXN];

void load() {
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 1; i <= N; i++) {
		scanf("%d", perm + i);
		inv[perm[i]] = i;
	}
}

ll rec(int num, int mx) {
	ll &ref = dp[num][mx];
	if (ref != INF)
		return ref;
	if (num > N)
		return ref = 0;
	if (mx > inv[num]) 
		return ref = rec(num + 1, mx) + A;
	return ref = min(rec(num + 1, inv[num]), rec(num + 1, mx) + B);
}

ll solve() {
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = INF;
			
	return rec(1, 0);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)

int const N = 5000;
ll dp[N + 1][N + 1];
int x[N + 1], in[N + 1];

inline void up(ll &x, ll y) { if (y < x)x = y; }

int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	f(i, 1, n + 1)scanf("%d", x + i);
	f(i, 1, n + 1)in[x[i]] = i;
	f(i, 0, n + 1)f(j, 0, n + 1)dp[i][j] = 1e18;
	dp[0][0] = 0;
	f(p, 0, n + 1)f(i, 0, n){
		int lc = in[i + 1];
		up(dp[p][i + 1], dp[p][i] + (lc < p ? a : b));
		if (lc >= p)up(dp[lc][i + 1], dp[p][i]);
	}
	ll an = 1e18;
	f(i, 0, n + 1)up(an, dp[i][n]);
	printf("%lld\n", an);
}
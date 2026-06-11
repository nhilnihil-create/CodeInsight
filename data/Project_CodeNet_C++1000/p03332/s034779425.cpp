/**/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>

typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

const LL MOD = 998244353, maxN = 1000000 + 24;
int N, a, b;
LL K, ans;
LL f[maxN], inv[maxN];

LL Pow(LL x, LL y)
{
	LL res = 1;
	while (y) {
		if (y&1) res = res % MOD * x % MOD;
		x *= x; x %= MOD; y >>= 1;
	}
	return res;
}

LL Com(LL x, LL y)
{
	if (x < y) return 0;
	return f[x] % MOD * inv[y] % MOD * inv[x-y] % MOD;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	f[0] = 1;
	for (int i = 1; i < maxN; i++) f[i] = f[i-1] % MOD * i % MOD ;
	inv[maxN-1] = Pow(f[maxN-1], MOD-2);
	for (int i = maxN - 2; i >= 0; i--) inv[i] = inv[i+1] % MOD * (i+1) % MOD;
		 // printf("%lld\n", Pow(2, 4));
	// for (int i = 0; i < 10; i++) printf("f = %lld, inv = %lld\n", f[i], inv[i]);
	while (scanf("%d%d%d%lld", &N, &a, &b, &K) == 4) {
		ans = 0;
		if (!K) { puts("1"); continue; }
		for (int i = 1; i <= N; i++) {
			LL t = K - a*i;
			if (t < 0 || (t % b)) continue;
			LL j = t / b;
			ans = (ans + Com(N, i) * Com(N, j) + MOD) % MOD;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
/*
    input:
    output:
    modeling:
    methods:
    complexity:
    summary:
*/
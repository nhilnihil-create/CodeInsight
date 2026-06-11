#include<iostream>
#include<cstdio>
#define REG register
#define LLI long long
#define MOD 1000000007
#define MXN 100010

int n;
LLI a[MXN],
	inv[MXN],
	pre[MXN];

int main() {
	REG int i, j;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%lld", a+i);
	inv[1] = 1;
	for(i = 2; i <= n; i++)
		inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
	for(i = 1; i <= n; i++)
		pre[i] = (pre[i-1] + 1*inv[i]) % MOD;
	REG LLI ans = 0, fac = 1;
	for(i = 1; i <= n; i++)
		ans = (ans + a[i]*(pre[i]+pre[n-i+1]-1) % MOD) % MOD,
		fac = (fac * i) % MOD;
	ans = ans * fac % MOD;
	printf("%lld\n", ans);
	
	return 0;
}

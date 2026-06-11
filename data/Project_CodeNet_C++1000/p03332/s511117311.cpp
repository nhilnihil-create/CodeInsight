#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const ll MOD = 998244353;

int n;

ll A,B,K,ans;
ll fac[MAXN];
ll inv[MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(ll x,ll y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d%lld%lld%lld",&n,&A,&B,&K);
	init();
	for (int i = 0;i <= n && i * A <= K;i++)
		if ((K - i * A) % B == 0)
			(ans += C(n,i) * C(n,(K - i * A) / B)) %= MOD;
	printf("%lld\n",ans);
	return 0;
}
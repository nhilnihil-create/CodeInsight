#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 100005;

int a[MAXN], inv[MAXN], pref[MAXN];

int n, res = 0; 

void init()
{
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	pref[1] = inv[1];
	for (int i = 2; i <= n; i++)
		pref[i] = ((ll)pref[i - 1] + inv[i]) % MOD;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	init();
	for (int i = 1; i <= n; i++)
	{
		res = (res + ((ll)pref[i] + pref[n - i + 1] - pref[1]) % MOD * a[i] % MOD) % MOD;
		if (res < 0)
			res += MOD;
	}
	for (int i = 1; i <= n; i++)
		res = (ll)res * i % MOD;
	printf("%d\n", res);
	return 0;
}

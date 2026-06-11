#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 1000000007;

int n;

ll ans;
ll a[MAXN];
ll inv[MAXN];
ll sum[MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	inv[0] = 1;
	for (int i = 1;i <= n;i++)
		inv[i] = inv[i - 1] * i % MOD;
	inv[n] = power(inv[n],MOD - 2);
	for (int i = n;i >= 1;i--)
	{
		ll tmp = inv[i];
		inv[i] = inv[i] * inv[i - 1] % MOD;
		inv[i - 1] = tmp * i % MOD;
	}
	for (int i = 2;i <= n;i++)
		sum[i] = (sum[i - 1] + inv[i]) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	init();
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		(ans += (sum[i] + sum[n - i + 1] + 1) * a[i]) %= MOD;
	for (int i = 1;i <= n;i++)
		(ans *= i) %= MOD;
	cout << ans << endl;
	return 0;
}
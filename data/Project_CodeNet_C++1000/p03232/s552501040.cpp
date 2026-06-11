#include<bits/stdc++.h>
#define maxn 100010
#define ll long long
#define mod 1000000007
using namespace std;
int val[maxn], n, pre[maxn], fac[maxn], inv[maxn];
int C(int n, int m) {return (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;}
int calc(int a, int k)
{
	int ans = 1;
	while (k)
	{
		if (k % 2) ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		k /= 2;
	}
	return ans;
}
int solve(int tp)
{
	int res = 0;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (ll)fac[i - 1] * i % mod;
	for (int i = 0; i <= n; i++)
		inv[i] = calc(fac[i], mod - 2);
	for (int i = 1; i <= n; i++)
		pre[i] = (pre[i - 1] + val[i]) % mod;
	for (int i = 1; i <= n; i++)
	{
		int tmp = pre[n - i + 1];
		if (i == 1)
		{
			if (tp) res = (res + (ll)tmp * fac[n] % mod) % mod;
		}
		else
		{
			int sum = i - 1, xs;
			xs = (ll)fac[n - i] * fac[sum] % mod * C(n, i) % mod;
			res = (res + (ll)tmp * xs % mod) % mod;
		}
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	int res = solve(0);
	reverse(val + 1, val + n + 1);
	res = (res + solve(1)) % mod;
	printf("%d\n", res);
	return 0;
}
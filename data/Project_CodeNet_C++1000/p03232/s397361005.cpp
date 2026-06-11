#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100100;
const int mod = 1e9 + 7;
long long power(long long x, long long k)
{
	long long ans = 1;
	while(k)
	{
		if(k & 1)
			(ans *= x) %= mod;
		k >>= 1;
		(x *= x) %= mod;
	}
	return ans;
}
int n;
long long fac[maxn], invfac[maxn], inv[maxn], hinv[maxn];
void init()
{
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	invfac[n] = power(fac[n], mod - 2);
	for(int i = n - 1; i >= 1; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= n; i ++)
		inv[i] = fac[i - 1] * invfac[i] % mod;
	hinv[0] = 0;
	for(int i = 1; i <= n; i ++)
		hinv[i] = (hinv[i - 1] + inv[i]) % mod;
}
long long ans = 0;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	init();	
	for(int i = 1; i <= n; i ++)
	{
		long long a;
		cin >> a;
		(ans += a * (hinv[i] + hinv[n - i + 1] - 1)) %= mod;
	}
	cout << ans * fac[n] % mod << endl;
	return 0;
}
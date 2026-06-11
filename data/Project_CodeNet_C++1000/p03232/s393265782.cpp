#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
ll a[MAXN], dp[MAXN], n, fact[MAXN], facrev[MAXN];
ll pwr(ll a, ll b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	ll c = pwr(a, b / 2);
	c = (c * c) % MOD;
	if(b % 2)
		c = (c * a) % MOD;
	return c;
}
ll inv(ll p)
{
	return pwr(p, MOD - 2);
}
ll C(ll n, ll k)
{
	ll mul = fact[n];
	mul = (mul * facrev[k]) % MOD;
	mul = (mul * facrev[n - k]) % MOD;
	return mul;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD;
	facrev[MAXN - 1] = inv(fact[MAXN - 1]);
	for (int i = MAXN - 1; i > 0; i--)
		facrev[i - 1] = (facrev[i] * i) % MOD;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = i * dp[i - 1] % MOD + fact[i - 1], dp[i] %= MOD;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll t_pre = C(n, n - i - 1) * fact[n - i - 1] % MOD * dp[i + 1] % MOD;
		ll t_nxt = C(n, i) * fact[i] % MOD * dp[n - i] % MOD;
		t_pre = (t_pre + t_nxt - fact[n] + MOD) % MOD;
		ans = (ans + t_pre * a[i] % MOD) % MOD;
	}
	cout << ans;
}
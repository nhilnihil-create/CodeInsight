#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll n;
ll dp[100010];
ll a[100010];
ll fac[100010];
ll len[100010];
ll mypow(ll x, ll y){
	if (y == 0)return 1;
	if (y % 2){
		return (x*mypow((x*x) % mod, y / 2)) % mod;
	}
	else return mypow((x*x) % mod, y / 2);
}
ll sub(ll x, ll y){
	return (x - y + mod*mod) % mod;
}
ll add(ll x, ll y){
	return (x + y) % mod;
}
ll mul(ll x, ll y){
	return (x*y) % mod;
}
ll C(ll x, ll y){
	ll gap = fac[x];
	gap = mul(gap, mypow(fac[y], mod - 2));
	gap = mul(gap, mypow(fac[x - y], mod - 2));
	return gap;
}
ll H(ll x, ll y){
	if (x == 0)return 1;
	return C(x + y - 1, y);
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i <= 100000; i++)
		fac[i] = (fac[i - 1] * i) % mod;
	scanf("%lld", &n);
	len[1] = fac[n];
	for (int i = 2; i <= n; i++){
		len[i] = (len[i - 1] + mul(mul(H(i+1,n-i),fac[i-1]),fac[n-i]))%mod;
	}
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ll dap = 0;
	for (int i = 1; i <= n; i++){
		dap += mul(a[i], len[n - i + 1]);
		dap%=mod;
		dap += mul(a[i], len[i]);
		dap %= mod;
		dap = sub(dap, mul(fac[n], a[i]));
	}
	printf("%lld", dap);
}
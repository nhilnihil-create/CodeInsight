#include<iostream>
using namespace std;

#define MAX (100001)
#define MOD (1000000007)
long long fac[MAX] = { 1,1 };
long long inv[MAX] = { 1,1 };
long long invsum[MAX] = { 1,1 };

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		fac[i] = fac[i - 1] * i%MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		invsum[i] = (invsum[i - 1] + inv[i]) % MOD;
	}

	long long a, b,ans=0;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		b = (invsum[i] + invsum[n - i + 1] - 1) % MOD;
		ans += (a * b) % MOD;
		ans %= MOD;
	}
	ans *= fac[n] % MOD;
	ans %= MOD;

	cout<<ans<<endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint n;
llint a[100005];
llint sum[100005];

int main(void)
{
	make_fact();
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + modpow(i, mod-2), sum[i] %= mod;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += mod - a[i] * fact[n] % mod, ans %= mod;
	for(int i = 1; i <= n; i++){
		llint tmp = sum[i] + sum[n-i+1]; tmp %= mod;
		tmp *= fact[n], tmp %= mod;
		tmp *= a[i], tmp %= mod;
		ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}
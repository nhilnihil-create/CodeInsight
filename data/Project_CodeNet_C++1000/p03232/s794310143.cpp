#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

const int MOD = 1e9 + 7;

i64 mod_pow(i64 x, i64 n = MOD - 2) {
	i64 ret = 1;
	while(n) {
		if(n & 1) (ret *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return ret;
}

int main() {
	int n; scanf("%d", &n); std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	std::vector<i64> inv(n + 1);
	for(int i = 1; i <= n; i++) inv[i] = mod_pow(i);
	
	std::vector<i64> sum(inv.size() + 1);
	for(int i = 0; i < inv.size(); i++) sum[i + 1] = (sum[i] + inv[i]) % MOD;
	
	i64 latte = 1;
	for(i64 i = 1; i <= n; i++) (latte *= i) %= MOD;
	
	i64 ans = 0;
	for(int i = 0; i < n; i++) {
		i64 p = (sum[i + 2] - sum[2] + MOD) % MOD;
			p += (sum[n - i + 1] - sum[1] + MOD) % MOD;
			p %= MOD;
		(ans += p * latte % MOD * a[i] % MOD) %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}

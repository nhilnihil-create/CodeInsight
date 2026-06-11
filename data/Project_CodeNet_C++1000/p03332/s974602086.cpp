#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int mod = 998244353;

int n;
long long a, b, req;

int fact[300005], inv_fact[300005];

int expo(int a, int b){
	int c = 1, d = a;
	while(b){
		if(b & 1){
			c = 1LL * c * d % mod;
		}
		d = 1LL * d * d % mod;
		b >>= 1;
	}
	return c;
}

int ncr(int N, int R){
	int ret = fact[N];
	ret = 1LL * ret * inv_fact[R] % mod;
	ret = 1LL * ret * inv_fact[N - R] % mod;
	return ret;
}

int inv(int x){
	return expo(x, mod - 2);
}

int main(){
	fact[0] = inv_fact[0] = 1;
	for(int i = 1; i <= 300000; i++){
		fact[i] = 1LL * fact[i - 1] * i % mod;
		inv_fact[i] = inv(fact[i]);
	}
	
	scanf("%d %lld %lld %lld", &n, &a, &b, &req);
	
	int ans = 0;
	
	for(int i = 0; i <= n; i++){
		long long remain = req - i * a;
		if(remain < 0 || remain % b > 0){
			continue;
		}
		long long need = remain / b;
		if(need > n){
			continue;
		}
		
		ans = (ans + 1LL * ncr(n, i) * ncr(n, need)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
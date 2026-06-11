#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long mod = 1e9 + 7;

long long a[N], pre[N], inv[N];

long long extgcd(long long a, long long b, long long& x, long long& y){
	long long d = a;
	if (b != 0){
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else{
		x = 1;
		y = 0;
	}
	return d;
}

long long mod_inverse(long long a){
	long long x, y, m;
	m = mod;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

int main(){
	int n;
	long long ans, jc;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = 1; i <= n; i++) inv[i] = mod_inverse(1LL * i);
	pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + inv[i]) % mod;
	ans = 0;
	for (int i = 1; i <= n; i++){
		ans += ((pre[i] + pre[n - i + 1] - 1) % mod) * a[i] % mod;
		ans %= mod;
	}
	for (int i = 1; i <= n; i++){
		ans *= i;
		ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
}
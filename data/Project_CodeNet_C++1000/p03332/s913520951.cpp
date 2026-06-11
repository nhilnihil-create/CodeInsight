#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstring>
#include<iostream>
#define LL long long
const LL mod = 998244353;
const int N = 3e5 + 3;
LL p[N],inv[N];
inline LL quick(LL a,LL b){
	LL res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}	
	return res;
}
inline LL C(LL n,LL m){
	return p[n] * inv[m] % mod * inv[n - m] % mod;	
} 
inline LL mo(LL X){
	if(X >= mod) X -= mod;
	return X;
}
int main(){
	p[0] = 1;p[1] = 1;inv[0] = 1;inv[1] = 1;
	for(int i = 2;i <= 300000;++i){
		p[i] = p[i - 1] * i % mod;
		inv[i] = quick(p[i],mod - 2);	
	}
	LL n,a,b,k;LL ans = 0;
	std::cin >> n >> a >> b >> k;
	for(int i = 0;i <= n;++i){
		LL t = k - a * i;
		if(t < 0 || t % b != 0) continue;
		LL g = t / b;
		if(g > n) continue;
		ans = mo(ans + C(n,i) * C(n,g) % mod);
	}
	printf("%lld\n",ans);
	return 0;
}
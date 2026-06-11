#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

#define LL long long
#define mod 998244353
const int N = 3e5+10;

LL a,b,n,k,inv[N],ans;

inline LL fast_pow(LL a,LL b,LL p) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans % p;
}
inline LL calc(LL a,LL b) {
	return inv[b] * fast_pow(inv[b - a],mod - 2,mod) % mod * fast_pow(inv[a],mod - 2,mod) % mod;
}
void init() {
	inv[0] = 1;
	for(int i = 1 ; i <= N ; i++)
		inv[i] = inv[i - 1] * i % mod;
}

int main() {
	init();
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	//cout<<ans<<endl;
	ans = 0;
	for(int i = 0 ; i <= n ; i++) {
		if(k - i * a < 0) break;
		if((k - i * a) % b == 0) { //j must be an integer
			LL j = (k - i * a) / b;
		//	if(j > n) continue;
			if(j <= n) {
				ans += calc(i,n) * calc(j,n) % mod;
				ans %= mod;
			}
			
		}
	}
	printf("%lld \n",ans);
	return 0;
}
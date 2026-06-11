#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i = a;i < b;i++)
#define rep_(i,a,b) for(int i = a;i <= b;i++)

const int maxn = 100010;
const ll mod = 1000000007;
ll a[maxn];

ll quick_pow(ll x,ll tms) {
	ll ret = 1;
	while(tms) {
		if(tms&1) (ret *= x) %= mod;
		(x *= x) %= mod;
		tms >>= 1;
	}
	return ret;
}

ll inv(ll x) {
	return quick_pow(x,mod-2);
}

int main() {
	int n;
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i]);
	ll ans = 0;
	ll multi = 0;
	ll stair = 1;
	rep_(i,1,n) (stair *= i) %= mod;
	rep_(i,1,n) (multi += stair*inv(i)) %= mod;
	(ans += a[0]*multi) %= mod;
	ll l = 1,r = n;
	rep(i,1,n) {
		(multi -= stair*inv(r--)) %= mod;
		(multi += stair*inv(++l)) %= mod;
		ans += a[i]*multi;
		ans %= mod;
	}
	if(ans < 0) ans += mod;
	printf("%lld\n",ans);
	return 0;
}

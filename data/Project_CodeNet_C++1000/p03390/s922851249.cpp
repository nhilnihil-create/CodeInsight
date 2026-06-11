#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
int main() {
	LL i, j, k;
	LL T;
	scanf("%lld", &T);
	while(T--){
		LL x, y;
		scanf("%lld%lld", &x, &y);
		LL L = 0, R = 1e9, ret;
		while(L <= R){
			LL mid = L+R>>1;
			if(mid*mid < x*y){ ret = mid; L = mid+1; }
			else R = mid-1;
		}
		LL p = ret;
		LL ans = 2*p;
		if(x <= p) ans--;
		if(y <= p) ans--;
		if(p*(p+1) >= x*y) ans--;
		printf("%lld\n", ans);
	}
	return 0;
}
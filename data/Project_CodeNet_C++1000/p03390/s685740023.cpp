#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;

int n;
LL a, b;

LL Get_sqrt(LL x) 
{
	LL l = 1, r = 1e9 + 10;
	LL ans = 1;
	while(l <= r) {
		LL mid = (l + r) >> 1;
		if(mid * mid <= x) ans = mid, l = mid + 1; 
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a, &b);
		LL x = Get_sqrt(a * b - 1LL);
		LL ans;
		if(x * (x + 1LL) <= a * b - 1LL) {
			ans = x * 2LL;
			if(x >= min(a, b)) ans--;
		}
		else {
			ans = 2LL * x - 1LL;
			if(x >= min(a, b)) ans--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
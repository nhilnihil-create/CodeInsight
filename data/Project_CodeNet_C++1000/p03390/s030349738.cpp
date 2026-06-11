#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

typedef long long LL;
using namespace std;
int n;

LL Get_sqrt(LL x) 
{
	LL l = 1, r = 1e9 + 10;
	LL ans = 0;
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
	for (int i = 1; i <= n; i++) {
		LL A, B; scanf("%lld%lld", &A, &B);
		LL ans = 0;
		LL t = Get_sqrt(A * B - 1);
		if(t * (t + 1) > A * B - 1) ans = 2 * t - 1; 
		else ans = 2 * t;
		if(A * A <= A * B - 1) ans--; if(B * B <= A * B - 1) ans--;
		printf("%lld\n", ans);
	}
	return 0;
}
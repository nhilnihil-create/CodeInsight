#include <cstdio>
#include <algorithm>
#define maxn 200005
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int n, a[maxn], x;

signed main(){
	scanf("%lld%lld", &n, &x);
	a[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += a[i - 1];
	
	int ans = INF, sum;
	for (int k = 1; k <= n; k++){
		sum = x * n + x * k; int t = 3;
		for (int i = n; i >= 1; i -= k){
			sum += (a[i] - a[max(0ll, i - k)]) * max(5ll, t), t += 2;
			if (sum >= ans) break;
		}
		ans = min(ans, sum);
	} printf("%lld\n", ans);
	
	return 0;
} 
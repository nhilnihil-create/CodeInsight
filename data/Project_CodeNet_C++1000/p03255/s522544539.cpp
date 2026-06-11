#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, x;
long long a[maxn], ans = 1e18;

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	reverse(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++) a[i] += a[i - 1];
	for(int i = 1;i <= n;i++){
		long long sum = 1ll * (i + n) * x;
		for(int j = 1, cnt = 1;j <= n;j += i, cnt++){
			int k = min(j + i - 1, n);
			sum += (cnt == 1 ? 5 : (2 * cnt + 1)) * (a[k] - a[j - 1]);
			if(sum >= ans) break;
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
}
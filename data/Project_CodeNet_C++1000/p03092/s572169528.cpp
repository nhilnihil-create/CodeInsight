#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
const int maxn = 5e3 + 5;
LL f[maxn], mn, ans;
int a[maxn], n, A, B, pos[maxn];
int main() {
	scanf("%d%d%d", &n, &A, &B);
	for(register int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]), pos[a[i]] = i;
	memset(f, 0x3f, sizeof(f)), f[0] = 0;
	ans = 0x3f3f3f3f3f3f3f3f;
	for(register int i = 1; i <= n; ++i) {
		mn = 0x3f3f3f3f3f3f3f3f;
		for(register int j = 0; j <= n; ++j) {
			mn = min(mn, f[j]);
			if(pos[i] < j) f[j] = mn + A;
			else if(pos[i] > j) f[j] = mn + B;
			else f[j] = mn;
		}
	}
	for(register int i = 1; i <= n; ++i)
		ans = min(f[i], ans);
	printf("%lld", ans);
	return 0;
} 
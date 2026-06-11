#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 5050;
long long f[2 * maxn], nf[2 * maxn];
int p[maxn];
int main(){
	int n, A, B; scanf("%d %d %d", &n, &A, &B);
	for(int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		p[x] = 2 * i;
	}
	int l = 2 * n + 1;
	for(int i = 1; i <= n; i++){
		long long mi = f[1];
		f[1] += B;
		for(int j = 2; j <= l; j++){
			mi = min(mi, f[j]);
			long long cost = (p[i] < j) * A + (p[i] > j) * B;
			f[j] = mi + cost;
		}
	}
	long long ans = 1ll<<62;
	for(int j = 1; j <= l; j++) ans = min(ans, f[j]);
	printf("%lld\n", ans);
	return 0;
}

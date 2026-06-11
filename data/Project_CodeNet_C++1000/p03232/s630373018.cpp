#include<cstdio>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 100003, p = 1000000007;
int n, a[N], inv[N], ans, res;
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++)
		scanf("%d", a + i);
	inv[1] = 1;
	for(Rint i = 2;i <= n;i ++)
		inv[i] = (LL) inv[p % i] * (p - p / i) % p;
	for(Rint i = 1;i <= n;i ++)
		inv[i] = (inv[i] + inv[i - 1]) % p;
	for(Rint i = 1;i <= n;i ++)
		ans = (ans + (LL) (inv[n - i + 1] + inv[i] - 1) * a[i]) % p;
	res = 1;
	for(Rint i = 2;i <= n;i ++)
		res = (LL) res * i % p;
	printf("%lld", (LL) ans * res % p);
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
const int Mod = 1e9 + 7;
int N;
ll A[MAXN];
ll fac[MAXN], inv[MAXN];
ll ans;

int main() {
	register int i;
	scanf("%d", &N);
	for(*fac = i = 1; i <= N; ++i) fac[i] = 1ll * fac[i - 1] * i % Mod;
	for(inv[1] = 1, i = 2; i <= N; ++i) inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(i = 1; i <= N; ++i) inv[i] = (ll) (inv[i] + inv[i - 1]) % Mod;
	for(i = 1; i <= N; ++i)
		scanf("%lld", A + i),
		ans = (ll) (ans + A[i] * (inv[i] + inv[N - i + 1] - 1 + Mod) % Mod) % Mod;
	printf("%lld\n", (ll) ans * fac[N] % Mod);
	return 0;
}
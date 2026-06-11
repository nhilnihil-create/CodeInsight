#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010, P = 1000000007;

int n;
int a[N], h[N];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	h[1] = 1;
	for (int i = 2; i <= n; ++i)
		h[i] = -(P / i) * (ll)h[P % i] % P + P;
	for (int i = 2; i <= n; ++i)
		if ((h[i] += h[i - 1]) >= P)
			h[i] -= P;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + a[i] * ((ll)h[i] + h[n - i + 1] - 1)) % P;
	for (int i = 1; i <= n; ++i)
		ans = ans * (ll)i % P;
	printf("%d\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

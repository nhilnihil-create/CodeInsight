#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	register int T, x, y;
	register long long ans, p;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &y);
		ans = sqrt(1ll * x * y - 1);
		if (1ll * ans * ans > 1ll * x * y - 1) --ans;
		p = ans * 2 - 1;
		if (ans * ans + ans > 1ll * x * y - 1) --p;
		if (x == y) ++p;
		printf("%lld\n", p);
	}
	return 0;
}
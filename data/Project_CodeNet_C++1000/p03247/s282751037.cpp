#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

int n, m, x[N], y[N], d[N];
bool tg[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", x + i, y + i);
		tg[(x[i] + y[i]) & 1] = 1;
	}
	if(tg[0] & tg[1]) return puts("-1") & 0;
	if(tg[0]) d[++ m] = 1;
	for(int i = 30; ~ i; i --) d[++ m] = 1 << i;
	printf("%d\n", m);
	for(int i = 1; i <= m; i ++) printf("%d%c", d[i], " \n"[i == m]);
	for(int i = 1; i <= n; i ++, putchar('\n')) {
		for(int j = 1; j <= m; j ++) {
			if(abs(x[i]) > abs(y[i])) {
				if(x[i] > 0) x[i] -= d[j], putchar('R');
				else x[i] += d[j], putchar('L');
			} else {
				if(y[i] > 0) y[i] -= d[j], putchar('U');
				else y[i] += d[j], putchar('D');
			}
		}
	}
	return 0;
}

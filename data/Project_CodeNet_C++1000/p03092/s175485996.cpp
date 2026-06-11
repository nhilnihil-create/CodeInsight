#include <bits/stdc++.h>

#define LL long long
#define pa pair<int,int>
using namespace std;
const int N = 5001;
const int inf = 2147483647;

int _max(int x, int y) {return x > y ? x : y;}
LL _min(LL x, LL y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int a[N]; LL f[N][N];

int main() {
	int n = read(), A = read(), B = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	memset(f, 63, sizeof(f)); f[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(a[i] > j) {
				f[i][j] = _min(f[i][j], f[i - 1][j] + A);
				f[i][a[i]] = _min(f[i][a[i]], f[i - 1][j]);
			} else f[i][j] = _min(f[i][j], f[i - 1][j] + B);
		}
	} LL ans = f[0][1];
	for(int i = 0; i <= n; i++) ans = _min(ans, f[n][i]);
	printf("%lld\n", ans);
	return 0;
}


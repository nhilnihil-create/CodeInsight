#include<cstdio>
struct with {
	int x, y, cost;
} ar[66];
int L;
bool binary[30];
int n,m,base;
int ex[30];
void ar_push(int x, int y, int cost) {
	ar[++m].x = x; ar[m].y = y; ar[m].cost = cost;
}
int main() {
	scanf("%d", &L);
	base=1;
	while (L > 0) {
		ex[n] = base;
		binary[n++] = L % 2;
		L /= 2; base *= 2;
	}
	int i;
	base /= 2;
	int exx = base;
	for (i = 1; i < n; i++) {
		exx /= 2;
		ar_push(i, i + 1, 0);
		ar_push(i, i + 1, exx);
	}
	for (i = n - 2; i >= 0; i--) {
		if (binary[i]) {
			ar_push(1, n - i, base);
			base += ex[i];
		}
	}
	printf("%d %d\n", n, m);
	for (i = 1; i <= m; i++) {
		printf("%d %d %d\n", ar[i].x, ar[i].y, ar[i].cost);
	}
	return 0;
}
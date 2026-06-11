#include <cstdio>
#include <algorithm>
using namespace std;
int n, cnt, sum, u[100], v[100], w[100], val[100];
void ins(int x, int y, int z) {
	u[cnt] = x;
	v[cnt] = y;
	w[cnt++] = z;
}
int main() {
	val[1] = 1;
	for (int i = 2; i <= 19; ++i) {
		val[i] = val[i-1] << 1;
		ins(i-1, i, 0);
		ins(i-1, i, val[i-1]);
	}
	scanf("%d", &n);
	for (int i = 19; i >= 1; --i) {
		while (n >= val[i]) {
			ins(i, 20, sum);
			sum += val[i];
			n -= val[i];
		}
	}
	printf("20 %d\n", cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d %d %d\n", u[i], v[i], w[i]);
}
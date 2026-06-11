#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000], n, Mn = 2e9, r;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	sort(w + 1, w + n + 1);
	for (i = 1; i < n; i++) {
		if (abs(w[n] - w[i] * 2) < Mn)Mn = abs(w[n] - w[i] * 2), r = w[i];
	}
	printf("%d %d\n", w[n], r);
}
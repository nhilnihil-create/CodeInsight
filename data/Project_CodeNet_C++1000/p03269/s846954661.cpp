#include <bits/stdc++.h>
#include <bits/extc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;

int lg[1000010];

int main() {
	int L; scanf("%d", &L);
	for (int i = 2; i <= 1000000; ++i)
		lg[i] = lg[i >> 1] + 1;
	int m = 0;
	for (int i = L; i != 0; i -= 1 << lg[i])
		++m;
	printf("%d %d\n", lg[L] + 1, m - 1 + (lg[L] << 1));
	for (int i = 0; i < lg[L]; ++i)
		printf("%d %d %d\n%d %d %d\n", i + 1, i + 2, 1 << i, i + 1, i + 2, 0);
	for (int i = L; i != 1 << lg[i]; i -= lowbit(i))
		printf("%d %d %d\n", lg[lowbit(i)] + 1, lg[i] + 1, i - lowbit(i));
	return 0;
}


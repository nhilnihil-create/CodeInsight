#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define LL long long
int a[M], b[M];
inline bool cmp(int x, int y) {
	return x > y;
}
int main() {
	LL Ans = 0;
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	sort(a, a + n + 1, cmp);
	sort(b, b + n + 1);
	for(int i = 0; i <= n; ++ i) {
		if(a[i] >= b[i]) {
			Ans += 2 * (a[i] - b[i]);
		}
	}
	printf("%lld\n", Ans);
}
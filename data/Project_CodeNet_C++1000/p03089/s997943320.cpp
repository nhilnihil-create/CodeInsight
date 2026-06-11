#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7;
int n, a[maxn], ans[maxn];

bool cal() {
	for (int i = 1; i <= n; ++i) {
		int now = i, pos = 0;
		for (int j = n; j; --j) {
			if(a[j] == now) {
				pos = j;
				break;
			}
			if(!a[j]) --now;
		}
		if(!pos) return 0;
		ans[i] = a[pos]; a[pos] = 0;
	}
	for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(!cal()) printf("-1\n");
	return 0;
}
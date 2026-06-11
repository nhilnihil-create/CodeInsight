#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
	//freopen("a.in", "r", stdin);
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int mx = 1;
	for(int i = 2; i <= n; ++ i) {
		if(min(a[n] - a[i], a[i]) > min(a[n] - a[mx], a[mx])) {
			mx = i;
		}
	}
	printf("%d %d\n", a[n], a[mx]);
}
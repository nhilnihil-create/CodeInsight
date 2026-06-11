#include <bits/stdc++.h>
using namespace std;
int n, K, Q, a[2010], b[2010];
int dbg;
int f(int lo, int hi) {
	for(int i=1; i<=n; i++) {
		if(a[i] < lo) b[i] = 0;
		else if(a[i] <= hi) b[i] = 1;
		else b[i] = 2;
	}
	int tot = 0, cnt = 0, r = 0;
	for(int i=1; i<=n; i++) {
		if(b[i]) {
			tot++;
			if(b[i] == 1) cnt++;
			if(i == n || !b[i+1]) {
				if(tot < K) continue;
				r += min(tot - K + 1, cnt);
			}
		} else tot = cnt = 0;
	}
	//printf("lo:%d, hi:%d, r:%d\n", lo, hi, r);
	return r;
}
int main() {
	scanf("%d%d%d", &n, &K, &Q);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	int res = 1e9;
	for(int i=1; i<=n; i++) {
		int lo = a[i], hi = 1e9 + 10;
		while(lo < hi) {
			int mid = (lo + hi) / 2;
			if(f(a[i], mid) >= Q) hi = mid;
			else lo = mid + 1;
		}
		if(lo == 1e9 + 10) continue;
		//printf("a[i]:%d, lo:%d\n", a[i], lo);
		res = min(res, lo - a[i]);
	}
	printf("%d", res);
	return 0;
}
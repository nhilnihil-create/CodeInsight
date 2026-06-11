//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200000

int n;
int a[2][MAXN];
int b[2][MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int k=0; k<2; k++)
		for (int i=0; i<n; i++)
			scanf("%d", &a[k][i]);
	return 1;
}

void init() {
}

int cnt(int *a, int n, int x, int s, int t) {
	int is = lower_bound(a, a+n, s-x)-a;
	int it = lower_bound(a, a+n, t-x)-a;
	return it-is;
}

long solve() {
	long ans = 0;
	for (int bit=0; bit<29; bit++) {
		int t = 1<<bit;
		for (int k=0; k<2; k++) {
			for (int i=0; i<n; i++)
				b[k][i] = a[k][i] % (2*t);
			sort(b[k], b[k]+n);
		}
		int r = 0;
		for (int i=0; i<n; i++) {
			r += cnt(b[0], n, b[1][i], 1*t, 2*t);
			r += cnt(b[0], n, b[1][i], 3*t, 4*t);
		}
		if (r%2) ans += t;
	}
	return ans;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}




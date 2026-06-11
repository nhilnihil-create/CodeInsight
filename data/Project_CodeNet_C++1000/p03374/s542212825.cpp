//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n;
long c;
long x[MAXN], y[MAXN];
long v[MAXN];
long left[MAXN+1], right[MAXN+1];
long lmax[MAXN+1], rmax[MAXN+1];

int input() {
	if (scanf("%d %ld", &n, &c) < 0) return 0;
	for (int i=0; i<n; i++)
		scanf("%ld %ld", &x[i], &v[i]);
	return 1;
}

void init() {
}

void calc(long *x, long *v, long *r, long *m) {
	long s = 0;
	r[0] = m[0] = 0;
	for (int i=0; i<n; i++) {
		s += v[i];
		r[i+1] = s-x[i];
		m[i+1] = max(m[i], r[i+1]);
	}
}

long solve() {
	calc(x, v, right, rmax);
	reverse(v, v+n);
	for (int i=0; i<n; i++)
		y[i] = c-x[n-1-i];
	calc(y, v, left, lmax);

	long r = 0;
	for (int i=0; i<=n; i++) {
		r = max(r, right[i] + lmax[n-i] - (i? x[i-1]:0));
		r = max(r, left[i]  + rmax[n-i] - (i? y[i-1]:0));
	}
	return r;
}

void output(long ans) {
	printf("%ld\n", ans);
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}




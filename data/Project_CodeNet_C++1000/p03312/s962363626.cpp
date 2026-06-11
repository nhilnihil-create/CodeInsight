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
long a[MAXN], b[MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%ld", &a[i]);
	return 1;
}

void init() {
}

//[0,p) & [p,n)
long diff(long *b, int n, int p) {
	return abs((b[n]-b[p]) - (b[p]-b[0]));
}

void calc(long *a, long *b, int n, int &p, long *m) {
	long s = b[n]-b[0];
	while (p<n-1 && (b[p]-b[0])*2 < s) p++;
	if (p>0 && diff(b, n, p-1) < diff(b, n, p)) p--;
	m[0] = b[p]-b[0];
	m[1] = b[n]-b[p];
}

long solve() {
	b[0] = 0;
	for (int i=0; i<n; i++)
		b[i+1] = b[i] + a[i];
	int f=1, g=1;
	long m[4];
	long r = INT_MAX;
	for (int k=2; k<=n-2; k++) {
		calc(a, b, k, f, m);
		g = max(1, g-k);
		calc(a+k, b+k, n-k, g, m+2);
		//p('k', k+1, 'f', f+1, 'g', g+1, 'm', m[0], m[1], m[2], m[3]);
		g += k;
		sort(m, m+4);
		r = min(r, m[3]-m[0]);
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




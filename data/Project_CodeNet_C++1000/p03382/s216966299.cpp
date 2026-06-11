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
int a[MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	return 1;
}

void init() {
}

int solve() {
	sort(a, a+n);
	int m = a[n-1], z = 0, t = 0;
	for (int i=0; i<n; i++) {
		int x = a[i];
		if (x > m-x) x = m-x;
		if (x > z) z = x, t = i;
	}
	printf("%d %d\n", m, a[t]);
	return 1;
}

void output(int ans) {
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		break;
	}
}



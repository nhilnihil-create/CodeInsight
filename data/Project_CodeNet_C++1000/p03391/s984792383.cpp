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
int a[MAXN], b[MAXN];

int input() {
	if (scanf("%d", &n) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);
	return 1;
}

void init() {
}

long solve() {
	long s = 0;
	for (int i=0; i<n; i++) s+= a[i];
	int m = INT_MAX;
	for (int i=0; i<n; i++)
		if (b[i] < a[i])
			m = min(m, b[i]);
	if (m==INT_MAX) return 0;
	return s - m;
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




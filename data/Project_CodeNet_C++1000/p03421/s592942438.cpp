//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 300000

int n, a, b;
int r[MAXN];

int input() {
	if (scanf("%d %d %d", &n, &a, &b) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	if (a+b-1>n) return 0;
	//if (a<=0 || b<=0 || long(a)*b<n) return 0;
	int t=n, s=1, p=0;
	while (p<n) {
		if (a<=0) return 0;
		int q = p;
		for (int i=0; i<a && p<n; i++) {
			r[p++] = t--;
		}
		reverse(r+q, r+p);
		a--;

		if (b<=0) return 0;
		b--;
		q = p;
		for (int i=0; i<b && p<n; i++) {
			r[p++] = s++;
		}
		reverse(r+q, r+p);
	}
	return 1;
}

void output(long ans) {
	if (!ans) {
		printf("-1\n");
		return;
	}
	for (int i=0; i<n; i++) printf("%d ", r[i]);
	printf("\n");
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




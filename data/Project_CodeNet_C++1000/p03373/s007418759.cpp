//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int a,b,c,x,y;

int input() {
	if (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	if (c*2 < a+b) {
		int d = min(x,y), z;
		if (d==x) {
			z = min(c*2, b)*(y-d);
		}
		else {
			z = min(c*2, a)*(x-d);
		}
		return d*2*c + z;
	}
	else {
		return x*a + y*b;
	}
	return 1;
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




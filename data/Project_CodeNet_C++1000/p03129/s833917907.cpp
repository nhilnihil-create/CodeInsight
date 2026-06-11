//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, k;

int input() {
	if (scanf("%d %d", &n, &k) < 0) return 0;
	return 1;
}

void init() {
}

long solve() {
	return (n+1)/2 >= k;
}

void output(long ans) {
	printf("%s\n", ans? "YES":"NO");
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




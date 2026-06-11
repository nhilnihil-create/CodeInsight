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
int s[3], t[3];

int input() {
	for (int i=0; i<3; i++) {
		if (scanf("%d %d", &s[i], &t[i]) < 0) return 0;
		s[i]--, t[i]--;
	}
	return 1;
}

void init() {
}

int check(int *e, int m) {
	int mark[4]={0};
	for (int i=0; i<m-1; i++)
		if (t[e[i]] != s[e[i+1]])
			swap(t[e[i+1]], s[e[i+1]]);
	mark[s[e[0]]] = 1;
	for (int i=0; i<m; i++) {
		if (i<m-1 && t[e[i]] != s[e[i+1]]) return 0;
		mark[t[e[i]]] = 1;
	}
	for (int i=0; i<4; i++)
		if (!mark[i]) return 0;
	return 1;
}

long solve() {
	int e[3]={0,1,2};
	while (1) {
		if (check(e, 3)) return 1;
		swap(s[e[0]], t[e[0]]);
		if (check(e, 3)) return 1;
		if (!next_permutation(e,e+3)) break;
	}
	return 0;
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




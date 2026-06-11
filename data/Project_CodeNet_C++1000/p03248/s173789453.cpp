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
char s[MAXN+1];
int f[MAXN];
int a[MAXN];

int input() {
	if (scanf("%s", s) < 0) return 0;
	n = strlen(s);
	return 1;
}

void init() {
}

int solve() {
	if (s[0]!='1' || s[n-1]!='0') return 0;
	int m = 0;
	for (int i=0; i<n-1; i++) {
		if (s[i] != s[n-2-i]) return 0;
		if (s[i]=='1' && i+1 >= (n+1)/2) {
			a[m++] = i+1;
		}
	}
	sort(a, a+m);
	memset(f, -1, sizeof(*f)*n);
	int v = m;
	for (int i=0; i<m; i++) {
		int k = a[i] - (i? a[i-1]: 0) - 1;
		for (int j=0; j<k; j++)
			f[v++] = i;
		if (i<m-1)
			f[i] = i+1;
		//printa(f, n);
	}
	f[v++] = m-1;
	//printa(a, m);
	return 1;
}

void output(int ans) {
	if (!ans) {
		printf("-1\n");
		return;
	}
	for (int i=0; i<n; i++)
		if (f[i]>=0) printf("%d %d\n", i+1, f[i]+1);
}

void cleanup() {
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//printf("\n");
		//break;
	}
}




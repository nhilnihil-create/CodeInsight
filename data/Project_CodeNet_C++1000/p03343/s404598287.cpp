//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, len, q;
int a[MAXN];

int input() {
	if (scanf("%d %d %d", &n, &len, &q) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	return 1;
}

void init() {
}

long solve() {
	int r = INT_MAX;
	for (int t=0; t<n; t++) {
		int x = a[t];
		vector<int> v;
		for (int i=0; i<n; ) {
			if (a[i]>=x) {
				vector<int> s;
				int j;
				for (j=i; j<n && a[j]>=x; j++)
					s.push_back(a[j]);
				i = j;
				sort(s.begin(), s.end());
				for (j=0; j+len<=s.size(); j++)
					v.push_back(s[j]);
			}
			else i++;
		}
		sort(v.begin(), v.end());
		if (q<=v.size())
			r = min(r, v[q-1]-v[0]);
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




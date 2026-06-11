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

int input() {
	if (scanf("%d", &n) < 0) return 0;
	return 1;
}

void init() {
}

typedef double T;

T f(long n) {
	T r = n;
	int s = 0;
	while(n) s += n%10, n /= 10;
	return r/s;
}

vector<long> check(vector<pair<T,long>> &a) {
	vector<long> r;
	sort(a.begin(), a.end());
	int n = unique(a.begin(), a.end()) - a.begin();
	long m = LONG_MIN;
	for (int i=0; i<n; i++) {
		if (m < a[i].second) r.push_back(a[i].second);
		m = max(m, a[i].second);
	}
	return r;
}

long solve() {
	vector<pair<T,long>> a;
	long b = 1;
	for (int i=0; i<15; i++) {
		for (int j=1; j<150; j++) {
			long x = b*j-1;
			if (x) a.push_back({f(x), x});
		}
		b *= 10;
	}
	vector<long> r = check(a);
	for (int i=0; i<n; i++)
		printf("%ld\n", r[i]);
	return 1;
}

void output(long ans) {
}

void cleanup() {
}

/*
void pre() {
	int n = 400000;
	vector<pair<T,int>> a;
	for (int i=1; i<=n; i++) {
		a.push_back({f(i),i});
	}
	for (auto x: check(a)) p(x);
}
*/

int main() {
	//pre(); return 0;
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}




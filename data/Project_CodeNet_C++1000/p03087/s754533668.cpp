
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC122C();

#if 1
int main()
{
	ABC122C();
	fflush(stdout);
	return 0;
}
#endif

static void ABC122C()
{
	int N, Q;
	getint(N, Q);

	std::string orgs;
	std::cin >> orgs;

	std::vector<int> acCounts(N + 1, 0);
	for (int i = 2; i <= N; i++) {
		acCounts[i] = acCounts[i - 1];
		if ((orgs[i - 1] == 'C') && (orgs[i - 2] == 'A')) {
			acCounts[i]++;
		}
	}
	for (int q = 0; q < Q; q++) {
		int li, ri;
		getint(li, ri);
		printf("%d\n", acCounts[ri] - acCounts[li]);
	}
}

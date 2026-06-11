
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

static void AGC024C();

#if 1
int main()
{
	AGC024C();
	fflush(stdout);
	return 0;
}
#endif

static void AGC024C()
{
	int N;
	getint(N);

	LLONG ans = 0;
	std::vector<LLONG> ai(N, 0);
	for (int i = 0; i < N; i++) {
		getint(ai[i]);
		if (ai[i] > 0) {
			ans++;
		}
		if (i) {
			if ((ai[i] <= ai[i - 1]) && (ai[i] > 1LL)) {
				ans += (ai[i] - 1LL);
			}
		}
	}
	if (ai[0] > 0) {
		printf("-1\n");
		return;
	}
	for (int i = 1; i < N; i++) {
		if (ai[i] - ai[i - 1] > 1) {
			printf("-1\n");
			return;
		}
	}

	printf("%lld\n", ans);
}


#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

static void AGC032A();

#if 1
int main()
{
	AGC032A();
	fflush(stdout);
	return 0;
}
#endif

static void AGC032A()
{
	int N;
	getint(N);

	std::vector<int> bn(N, 0), ans(N, 0);
	for (int i = 0; i < N; i++) {
		getint(bn[i]);
	}

	int nowLen = N;
	for (int i = N; i > 0; i--) {
		bool match = false;
		for (int j = i; j > 0; j--) {
			if (j == bn[j - 1]) {
				bn.erase(bn.begin() + (j - 1));
				ans[i - 1] = j;
				match = true;
				break;
			}
		}
		if (!match) {
			printf("-1\n");
			return;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
}

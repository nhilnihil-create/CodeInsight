
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

static void ABC117D();

#if 1
int main()
{
	ABC117D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC117D()
{
	int N;
	LLONG K;
	getint(N);
	getint(K);

	std::vector<LLONG> an(N);
	std::vector<int> bitSum(64, 0), kBits(64, 0);
	for (int i = 0; i < N; i++) {
		getint(an[i]);

		LLONG bit = 1;
		int pos = 0;
		while (bit <= an[i]) {
			if (bit & an[i]) {
				bitSum[pos]++;
			}
			bit <<= 1LL;
			pos++;
		}
	}

	LLONG bit = 1;
	int pos = 0;
	while (bit <= K) {
		if (bit & K) {
			kBits[pos]++;
		}
		bit <<= 1;
		pos++;
	}

	bool small = false;
	std::vector<int> bits(64, 0);
	for (int p = pos - 1; p >= 0; p--) {
		int better = 0;
		if (bitSum[p] * 2 < N) {
			better = 1;
		}

		if (!small) {
			if (kBits[p]) {
				bits[p] = better;
				if (better == 0) {
					small = true;
				}
			}
			else {
				bits[p] = 0;
			}
		}
		else {
			bits[p] = better;
		}
	}
	LLONG X = 0;
	for (int i = 0; i < pos; i++) {
		if (bits[i]) {
			X |= 1LL << i;
		}
	}

	LLONG ans = 0;
	for (int i = 0; i < N; i++) {
		ans += X ^ an[i];
	}
	printf("%lld\n", ans);
}

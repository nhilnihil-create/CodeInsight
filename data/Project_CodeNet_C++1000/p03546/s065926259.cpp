
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

static void ABC079D();

#if 1
int main()
{
	ABC079D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC079D()
{
	int H, W;
	getint(H, W);

	std::vector<std::vector<int>> power(10, std::vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			getint(power[i][j]);
		}
	}

	std::vector<std::vector<int>> wall(H, std::vector<int>(W));
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			getint(wall[h][w]);
		}
	}

	std::vector<std::vector<int>> minPower(10, std::vector<int>(10, 2000));
	for (int i = 0; i < 10; i++) {
		minPower[i][i] = 0;
	}

	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				power[i][j] = std::min(power[i][j], power[i][k] + power[k][j]);
			}
		}
	}

	int ans = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (wall[h][w] != -1) {
				ans += power[wall[h][w]][1];
			}
		}
	}
	printf("%d\n", ans);
}

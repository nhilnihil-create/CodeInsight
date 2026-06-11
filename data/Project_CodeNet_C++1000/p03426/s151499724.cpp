
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

static void ABC089D();

#if 1
int main()
{
	ABC089D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC089D()
{
	int H, W, D;
	getint(H, W, D);

	std::vector<std::pair<int, int>> valPos(H * W + 1, std::pair<int, int>(0, 0));

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			int val;
			getint(val);
			valPos[val].first = h + 1;
			valPos[val].second = w + 1;
		}
	}

	int gridCount = H * W;
	std::vector<std::vector<int>> cost(D + 1, std::vector<int>((gridCount / D) + 1, 0));
	for (int i = 1; i <= D; i++) {
		int mul = 1;
		int index = i + D;
		while (index <= gridCount) {
			int tmpCost = std::abs(valPos[index].first - valPos[index - D].first)
				+ std::abs(valPos[index].second - valPos[index - D].second);
			cost[i][mul] = tmpCost + cost[i][mul - 1];
			mul++;
			index = i + (D * mul);
		}
	}

	int Q;
	getint(Q);
	std::vector<LLONG> costs(Q, 0);
	for (int q = 0; q < Q; q++) {
		int now, end;
		getint(now, end);
		
		int firstIdx = end % D;
		if (!firstIdx) {
			firstIdx = D;
		}
		costs[q] = cost[firstIdx][(end - firstIdx) / D] - cost[firstIdx][(now - firstIdx) / D];
	}
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", costs[i]);
	}
}

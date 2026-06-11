
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

static void ABC088D();

#if 1
int main()
{
	ABC088D();
	fflush(stdout);
	return 0;
}
#endif

static void ABC088D()
{
	int H, W;
	getint(H, W);

	std::vector<std::string> grid(H);
	for (int i = 0; i < H; i++) {
		std::cin >> grid[i];
	}

	std::vector<std::vector<int>> dp(H, std::vector<int>(W, (int)MOD_NUM));

	std::queue<std::pair<int, int>> que;
	que.push(std::pair<int, int>(0, 0));
	dp[0][0] = 0;
	while (!que.empty()) {
		int dh[] = { 1, 0, -1, 0 };
		int dw[] = { 0, 1, 0, -1 };

		std::pair<int, int> pos = que.front(); que.pop();
		int nowStep = dp[pos.first][pos.second] + 1;
		for (int i = 0; i < 4; i++) {
			int nh = pos.first + dh[i];
			int nw = pos.second + dw[i];

			if ((nh >= 0) && (nh < H) && (nw >= 0) && (nw < W) && (grid[nh][nw] == '.') && (nowStep < dp[nh][nw])) {
				dp[nh][nw] = nowStep;
				if ((nh == (H - 1)) && (nw == (W - 1))) {
					while (!que.empty()) que.pop();
					break;
				}
				que.push(std::pair<int, int>(nh, nw));
			}
		}
	}

	if (dp[H - 1][W - 1] == MOD_NUM) {
		printf("-1\n");
		return;
	}
	
	int whiteCount = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (grid[h][w] == '.') {
				whiteCount++;
			}
		}
	}
	printf("%d\n", whiteCount - dp[H - 1][W - 1] - 1);
}

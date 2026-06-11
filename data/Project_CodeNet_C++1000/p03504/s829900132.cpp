
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
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void ABC080D();

int main()
{
	ABC080D();
	fflush(stdout);
	return 0;
}

static void ABC080D()
{
	int N, C;
	getint(N, C);

	int st, et, ch;
	std::vector<std::vector<int>> counter(100001, std::vector<int>(C, 0));
	for (int i = 0; i < N; i++) {
		getint(st, et, ch); st--; et--; ch--;	//	0-indexed
		counter[st][ch]++;
		counter[et][ch]--;
	}

	int needDeck = 0, recCount = 0, endShow = 0;
	for (int i = 0; i < 100001; i++) {
		endShow = 0;
		for (int ch = 0; ch < C; ch++) {
			recCount += counter[i][ch];
			if (counter[i][ch] < 0) {
				endShow++;
			}
		}
		needDeck = std::max(needDeck, recCount + endShow);
	}
	printf("%d\n", needDeck);
}

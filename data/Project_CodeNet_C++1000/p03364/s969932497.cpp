
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

static void AGC023B();

int main()
{
	AGC023B();
	fflush(stdout);
	return 0;
}

static void AGC023B()
{
	int N;
	getint(N);

	std::vector<std::string> grid(N);
	for (int i = 0; i < N; i++) {
		std::cin >> grid[i];
	}

	int ans = 0;
	for (int n = 0; n < N; n++) {
		bool allEqu = true;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (grid[r][(n + c) % N] != grid[c][(n + r) % N]) {
					allEqu = false;
					break;
				}
			}
		}
		if (allEqu) ans++;
	}
	printf("%d\n", ans * N);
}

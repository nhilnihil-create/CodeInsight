
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	int N;
	get(N);

	std::vector<std::pair<int, int>> edge;
	if (N % 2) {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (j == (N - i)) continue;
				edge.push_back(std::pair<int, int>(i, j));
			}
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (j == (N + 1 - i)) continue;
				edge.push_back(std::pair<int, int>(i, j));
			}
		}
	}

	int size = edge.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d %d\n", edge[i].first, edge[i].second);
	}
}

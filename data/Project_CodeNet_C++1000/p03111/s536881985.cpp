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
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static int dfs(std::vector<int>& len, int now, std::vector<std::vector<int>> sel, int A, int B, int C)
{
	int ans = MOD_NUM;
	if (now >= len.size()) {
		if (sel[0].size() == 0 || sel[1].size() == 0 || sel[2].size() == 0) {
			return MOD_NUM;
		}
		ans = 0;
		int a = 0;
		for (int i = 0; i < sel[0].size(); i++) {
			a += sel[0][i];
		}
		ans += (sel[0].size() - 1) * 10;
		ans += tp_abs(A - a);
		int b = 0;
		for (int i = 0; i < sel[1].size(); i++) {
			b += sel[1][i];
		}
		ans += (sel[1].size() - 1) * 10;
		ans += tp_abs(B - b);
		int c = 0;
		for (int i = 0; i < sel[2].size(); i++) {
			c += sel[2][i];
		}
		ans += (sel[2].size() - 1) * 10;
		ans += tp_abs(C - c);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i < 3) {
				sel[i].push_back(len[now]);
			}
			ans = std::min(ans, dfs(len, now + 1, sel, A, B, C));
			if (i < 3) {
				sel[i].erase(sel[i].end() - 1);
			}
		}
	}
	return ans;
}

static void exec()
{
	int N, A, B, C;
	get(N);
	get(A, B, C);

	std::vector<int> len(N);
	for (int i = 0; i < N; i++) {
		get(len[i]);
	}
	std::vector<std::vector<int>> sel(3);
	printf("%d\n", dfs(len, 0, sel, A, B, C));
}


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


static LLONG dfs(std::string& str, int nowd, int digit, int N)
{
	LLONG ans = 0;
	char num[] = { '0', '3', '5', '7' };
	if (nowd == digit) {
		for (int i = 0; i < 4; i++) {
			str[nowd - 1] = num[i];
			bool search = false;
			bool b3, b5, b7;
			b3 = b5 = b7 = false;
			for (int i = 0; i < digit; i++) {
				if (str[i] != '0') {
					search = true;
				}
				else if (search) {
					b3 = b5 = b7 = false;
					break;
				}

				switch (str[i]) {
				case '3':
					b3 = true;
					break;
				case '5':
					b5 = true;
					break;
				case '7':
					b7 = true;
					break;
				}
			}
			if (b3 && b5 && b7) {
				if (strtol(str.c_str(), 0, 10) <= N) {
					ans++;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			str[nowd - 1] = num[i];
			ans += dfs(str, nowd + 1, digit, N);
		}
	}
	return ans;
}

static void exec()
{
	LLONG N;
	get(N);

	std::string num;
	LLONG tmp = N;
	int digit = 0;
	while (tmp) {
		digit++;
		tmp /= 10;
		num += '0';
	}
	printf("%lld\n", dfs(num, 1, digit, N));
}

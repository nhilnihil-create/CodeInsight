
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

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	std::string orgs;
	std::cin >> orgs;
	int A, B, C, D;
	
	A = orgs[0] - '0';
	B = orgs[1] - '0';
	C = orgs[2] - '0';
	D = orgs[3] - '0';

	std::string op1, op2, op3;
	int flag[3][2] = { { 1, -1}, { 1, -1}, { 1, -1} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if ((A + B * flag[0][i] + C * flag[1][j] + D * flag[2][k]) == 7) {
					op1 = (flag[0][i] < 1) ? "-" : "+";
					op2 = (flag[1][j] < 1) ? "-" : "+";
					op3 = (flag[2][k] < 1) ? "-" : "+";
				}
			}
		}
	}
	printf("%d%s%d%s%d%s%d=7", A, op1.c_str(), B, op2.c_str(), C, op3.c_str(), D);
}
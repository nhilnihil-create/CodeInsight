#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>
using namespace std;
#define sci(n) scanf("%lld", &(n))
#define scd(n) scanf("%Ld", &(n))
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> pll;

LL gcd(LL a, LL b) { while (b) { int t = a%b; a = b; b = t; } return a; }

map<LL, LL> mp;

void init(LL n) {
	LL tmp = n;
	for (LL i = 2; i*i <= tmp; ++i) {
		while (n%i == 0) {
			n /= i;
			mp[i]++;
		}
	}
	if (n != 1) mp[n]++;
}
int main(void)
{
	LL n, p;
	sci(n); sci(p);
	init(p);
	LL ret = 1;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		(*iter).second /= n;
		ret *= (LL)pow((*iter).first, (*iter).second);
	}
	cout << ret;
	return 0;
}
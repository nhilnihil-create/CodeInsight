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

static void ABC085D();

#if 1
int main()
{
	ABC085D();
	fflush(stdout);
	return 0;
}
#endif

class ABC085Ddata {
public:
	LLONG damage = 0;
	LLONG id = 0;

	static bool sort_dmg(const ABC085Ddata& a, const ABC085Ddata& b) {
		return a.damage > b.damage;
	}
};
static void ABC085D()
{
	LLONG N, H;
	getint(N, H);

	std::vector<ABC085Ddata> an((int)N), bn((int)N);
	for (int i = 0; i < N; i++) {
		getint(an[i].damage, bn[i].damage);
		an[i].id = bn[i].id = i;
	}

	std::sort(an.begin(), an.end(), ABC085Ddata::sort_dmg);
	std::sort(bn.begin(), bn.end(), ABC085Ddata::sort_dmg);
	
	int throwCount = 0;
	for (int i = 0; i < N; i++) {
		if (an[0].damage < bn[i].damage) {
			throwCount++;
		}
		else {
			break;
		}
	}

	std::vector<LLONG> thDmgs(throwCount + 1, 0);
	for (int t = 1; t <= throwCount; t++) {
		thDmgs[t] = thDmgs[t - 1] + bn[t - 1].damage;
	}
	
	LLONG rest = H;
	LLONG attackCount = 0;
	for (int i = 1; i <= throwCount; i++) {
		attackCount = i; 
		if (thDmgs[i] >= rest) {
			break;
		}
	}
	rest = std::max<LLONG>((LLONG)0, rest - thDmgs[attackCount]);

	attackCount += rest / an[0].damage;
	if (rest % an[0].damage) attackCount++;

	printf("%lld\n", attackCount);
}

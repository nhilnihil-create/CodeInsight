#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n;
int a[MAXN];

int b[MAXN], nb;

int cnt[2 * MAXN + 1];

ll calc(int val) { // # medians <= val
	REPE(i, 2 * n) cnt[i] = 0;
	int at = n; ll ret = 0; ++cnt[at]; ll sum = 0;
	REP(i, n) {
		if (a[i] <= val) sum += cnt[at], ++at; else --at, sum -= cnt[at];
		ret += sum; ++cnt[at];
		//printf("\t%d: at=%d sum=%lld ret=%lld\n", i, at - n, sum, ret);
	}
	//printf("%d: %lld\n", val, ret);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);

	nb = 0; REP(i, n) b[nb++] = a[i]; sort(b, b + nb); nb = unique(b, b + nb) - b;
	ll total = (ll)n*(n + 1) / 2;
	int l = -1, r = nb - 1; // (l,r] med of med <= b[i]
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		ll cur = calc(b[m]);
		if (2 * cur <= total)  l = m; else r = m;
	}
	printf("%d\n", b[r]);
}

int main() {
	run();
	return 0;
}

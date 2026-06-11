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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;

char s[MAXN + 1]; int n;
int cnt[3];

void run() {
	scanf("%s", s); n = strlen(s);

	REP(i, 3) cnt[i] = 0; REP(i, n) ++cnt[s[i] - 'a'];
	int mn = cnt[0], mx = cnt[0]; FOR(i, 1, 3) { if (cnt[i] < mn) mn = cnt[i]; if (cnt[i] > mx) mx = cnt[i]; }
	printf("%s\n", mx - mn <= 1 ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}

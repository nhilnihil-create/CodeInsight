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

const int MAXLEN = 200000;

char s[MAXLEN + 1]; int n;

int best[1 << 26];

void run() {
	scanf("%s", s); n = strlen(s);
	memset(best, -1, sizeof(best));
	int cur = 0; best[cur] = 0;
	REP(i, n) {
		int x = s[i] - 'a'; cur ^= 1 << x;
		REP(j, 26) {
			int now = best[cur ^ (1 << j)];
			if (now != -1 && (best[cur] == -1 || now + 1 < best[cur])) best[cur] = now + 1;
		}
	}
	int ret = best[cur]; if (ret == 0) ret = 1;
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}

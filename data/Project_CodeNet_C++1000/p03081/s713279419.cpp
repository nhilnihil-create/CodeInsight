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

const int MAXN=200000;
const int MAXQ=200000;

int n,nq;
char s[MAXN+1];
int qc[MAXQ],qdir[MAXQ];

int sim(int at) {
	REP(i,nq) {
		if(s[at]==qc[i]) { if(qdir[i]=='L') --at; if(qdir[i]=='R') ++at; }
		if(at<0||at>=n) return at;
	}
	return at;
}

int calcleft() {
	int lo=0,hi=n+1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		int pos=sim(mi-1);
		if(pos==-1) lo=mi; else hi=mi;
	}
	return lo;
}

int calcright() {
	int lo=0,hi=n+1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		int pos=sim(n-mi);
		if(pos==n) lo=mi; else hi=mi;
	}
	return lo;
}

int solve() {
	return n-calcleft()-calcright();
}

void run() {
	scanf("%d%d",&n,&nq);
	scanf("%s",s);
	REP(i,nq) scanf(" %c %c",&qc[i],&qdir[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
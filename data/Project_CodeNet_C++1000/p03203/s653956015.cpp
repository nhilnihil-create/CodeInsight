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

const int MAXW=200000;
const int MAXH=200000;
const int MAXN=200000;

int h,w,n;
int px[MAXN],py[MAXN];

vector<int> ylst[MAXW];

int getfirst(int x,int y) {
	int idx=lower_bound(ylst[y].begin(),ylst[y].end(),x)-ylst[y].begin();
	return idx<SZ(ylst[y])?ylst[y][idx]:h;
}

int solve() {
	int ret=h;
	REP(i,n) ylst[py[i]].PB(px[i]);
	REP(y,w) sort(ylst[y].begin(),ylst[y].end());
	int cx=0,cy=0;
	while(true) {
		int right=getfirst(cx,cy);
		ret=min(ret,right);
		if(right==cx+1) break;
		++cx;
		if(cy==w-1) break;
		int up=getfirst(cx,cy+1);
		if(up!=cx) ++cy;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]),--px[i],--py[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}

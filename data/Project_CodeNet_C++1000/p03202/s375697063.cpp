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

const int MAXN=200000;

int n;
int a[MAXN];

pair<int,int> lst[MAXN]; int nlst;

bool can(int alph) {
	nlst=0;
	FOR(i,1,n) {
		if(a[i]>a[i-1]) continue;
		while(nlst>0&&lst[nlst-1].first>=a[i]) --nlst;
		if(alph==1) return false;
		for(int idx=a[i]-1;;--idx) {
			if(idx<0) return false;
			int val;
			if(nlst>0&&lst[nlst-1].first==idx) {
				val=lst[nlst-1].second+1;
				--nlst;
			} else {
				val=1;
			}
			if(val==alph) continue;
			lst[nlst++]=MP(idx,val);
			break;
		}
	}
	return true;
}

int solve() {
	int l=0,h=n;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	return h;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}

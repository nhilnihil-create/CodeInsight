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

const int MAXN=5000;

int n; ll A,B;
int p[MAXN];

int pos[MAXN];

ll dp[MAXN][MAXN]; // dp[i][j] = minimum cost to place [0..j] so that i is the last one of them that stays in place

void upd(ll &a,ll b) { a=min(a,b); }
ll solve() {
	REP(i,n) pos[p[i]]=i;
	//printf("pos:"); REP(i,n) printf(" %d",pos[i]); puts("");
	
	REP(i,n) REP(j,n) dp[i][j]=LLONG_MAX;
	REP(i,n) dp[i][i]=i*B;
	REP(j,n-1) REPE(i,j) if(dp[i][j]!=LLONG_MAX) {
		int k=j+1;
		// let k stay in same place
		if(pos[k]>pos[i]) upd(dp[k][k],dp[i][j]);
		// move k left
		if(pos[k]>pos[i]) upd(dp[i][k],dp[i][j]+B);
		// move k right
		if(pos[k]<pos[i]) upd(dp[i][k],dp[i][j]+A);
	}
	//REP(i,n) REP(j,n) if(dp[i][j]!=LLONG_MAX) printf("(%d,%d) = %lld\n",i,j,dp[i][j]);
	ll ret=LLONG_MAX; REP(i,n) ret=min(ret,dp[i][n-1]); return ret;
}

void run() {
	scanf("%d%lld%lld",&n,&A,&B);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}

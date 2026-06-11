/*
 * ARC096_D.cpp
 *
 *  Created on: May 17, 2018
 *      Author: 13743
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;

#define pb push_back
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

lng power(lng b, lng e) {lng sol=1; while(e>0) {if(e&1) {sol=sol*b;} e>>=1; b*= b;} return sol;}

lng x[100000];
lng v[100000];

lng pt[100000];
lng ptRev[100000];

lng pm[100000];
lng pmR[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	lng C;
	cin >> N >> C;
	REP(i, N) {
		cin >> x[i] >> v[i];
	}

	lng taken = 0;
	REP(i, N) {
		taken += v[i];
		pt[i] = taken - x[i];
	}
	taken = 0;
	FORD(i, N-1, 0) {
		taken += v[i];
		ptRev[N-1-i] = taken - (C-x[i]);
	}

	pm[0] = pt[0];
	pmR[0] = ptRev[0];
	FOR(i, 1, N-1) {
		pm[i] = max(pm[i-1], pt[i]);
		pmR[i] = max(pmR[i-1], ptRev[i]);
	}

	lng opt = max(pm[N-1], pmR[N-1]);
	opt = (opt > 0) ? opt : 0;
	REP(i, N-1) {
		opt = max(opt, pt[i] - x[i] + pmR[N-2-i]);
		opt = max(opt, ptRev[i] - (C-x[N-1-i]) + pm[N-2-i]);
	}
	cout << opt << endl;
}





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
lng ptR[100000];

lng ptm[100000];
lng ptmR[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	lng C;
	cin >> N >> C;
	REP(i, N) {
		cin >> x[i] >> v[i];
	}

	pt[0] = v[0];
	ptR[N-1] = v[N-1];
	FOR(i, 1, N-1) {
		pt[i] = pt[i-1] + v[i];
		ptR[N-1-i] = ptR[N-i] + v[N-1-i];
	}
	ptm[0] = max(pt[0]-2*x[0], 0LL);
	ptmR[N-1] = max(ptR[N-1]-2*(C-x[N-1]), 0LL);
	FOR(i, 1, N-1) {
		ptm[i] = max(ptm[i-1], pt[i] - 2*x[i]);
		ptmR[N-1-i] = max(ptmR[N-i], ptR[N-1-i] - 2*(C-x[N-1-i]));
	}

	lng opt = max(pt[N-1]-x[N-1], ptR[0]-(C-x[0]));
	REP(i, N-1) {
		lng tmp = max(pt[i]-x[i]+ptmR[i+1], ptR[i+1]-(C-x[i+1])+ptm[i]);
		opt = max(opt, tmp);
	}
	if(opt < 0) opt = 0;

	cout << opt << endl;
}





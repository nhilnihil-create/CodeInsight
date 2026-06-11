/*
 * ARC092_D.cpp
 *
 *  Created on: May 19, 2018
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

int a[200001];
int b[200001];
int bsort[200001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	REP(i, N) {
		cin >> a[i];
	}
	REP(i, N) {
		cin >> b[i];
	}

	int ans = 0;
	REP(c, 29) {
		int bits = 0;
		int T = 1<<c;
		REP(i, N) {
			bsort[i] = b[i] % (2*T);
		}
		sort(bsort, bsort+N);
		REP(i, N) {
			int amod = a[i] % (2*T);
			int l1 = T-amod;
			int r1 = 2*T-amod;
			int l2 = 3*T-amod;
			int r2 = 4*T-amod;
			bits += lower_bound(bsort, bsort+N, r1) - lower_bound(bsort, bsort+N, l1);
			bits += lower_bound(bsort, bsort+N, r2) - lower_bound(bsort, bsort+N, l2);
		}
		if(bits&1) {
			ans += (1<<c);
		}
	}

	cout << ans << endl;
}





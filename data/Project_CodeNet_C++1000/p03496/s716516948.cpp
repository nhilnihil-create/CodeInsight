/*
 * ABC081_D.cpp
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



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int a[51];
	cin >> N;

	int minI=1, maxI = 1;
	FOR(i, 1, N) {
		cin >> a[i];
		minI = (a[i] < a[minI]) ? i : minI;
		maxI = (a[i] > a[maxI]) ? i : maxI;
	}
	int piv = minI;
	if(a[minI] + a[maxI] > 0) {
		piv = maxI;
	}

	cout << 2*N-1 << "\n";
	FOR(i, 1, N) {
		cout << piv << " " << i << "\n";
	}
	if(a[piv] > 0) {
		FOR(i, 1, N-1) {
			cout << i << " " << i+1 << "\n";
		}
	}
	else {
		FORD(i, N, 2) {
			cout << i << " " << i-1 << "\n";
		}
	}
	cout << flush;
}





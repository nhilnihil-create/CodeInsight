/*
 * ARC095_D.cpp
 *
 *  Created on: May 18, 2018
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

int a[100000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	REP(i, N) {
		cin >> a[i];
	}
	sort(a, a+N);

	int n = a[N-1];
	int r = min(a[0], n - a[0]);
	int solR = a[0];
	FOR(i, 1, N-2) {
		int x = min(a[i], n - a[i]);
		if(x > r) {
			r = x;
			solR = a[i];
		}
	}
	cout << n << " " << solR << endl;
}





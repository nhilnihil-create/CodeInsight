#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

///////////////////////////

bool comp(int x[10], int y[10]) {
	ll xsum=0, ysum=0;
	repn(i,9){
		xsum += x[i];
		ysum += y[i];
	}

	if (xsum > ysum) { return true; }
	if (ysum > xsum) { return false; }

	repn(i, 9) {
		if (x[10 - i] > y[10 - i]) { return true; }
		if (y[10 - i] > x[10 - i]) { return false; }

	}

}




int main() {
	
	int N, M;
	cin >> N >> M;

	int bo[10];
	bo[1] = 2;
	bo[2] = 5;
	bo[3] = 5;
	bo[4] = 4;
	bo[5] = 5;
	bo[6] = 6;
	bo[7] = 3;
	bo[8] = 7;
	bo[9] = 6;

	int a[10];
	repn(i, M) cin >> a[i];

	int val[100000][10] = {};

	repn(i, N) {
		repn(j, 9) {
			val[i][j] = -1;
		}
	}

	repn(j, 9) {
		val[0][9] = 0;
	}

	repn(i, N) {
		repn(j, M) {
			int c = a[j];

			int nval[10];

			if (i >= bo[c]&&val[i-bo[c]][1]!=-1) {
				repn(k, 9) {
					if (k != c) { nval[k] = val[i - bo[c]][k]; }
					if (k == c) { nval[k] = val[i - bo[c]][k] + 1; }
				}

				

				if (comp(nval,val[i])) {
					repn(k, 9) {
						val[i][k] = nval[k];
					}
				}

				 
				

			}
		}

		
	}

	for(int k=9;k>0;k--) {
		while (val[N][k] > 0) {
			cout << k;
			val[N][k]--;
		}
	}


	system("PAUSE");
}
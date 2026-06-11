#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>


using namespace std;

typedef long long ll;

typedef vector<vector<ll>> V;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, ll> P;
#define mp(x, y) make_pair(x, y)

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define repm(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

const ll INF = 1e10;

int H, W;

V C(10, vll(10));
V A(310, vll(310));
V dist(15, vll(15, INF));



int main() {
	cin >> H >> W;
	
	rep(i, 10) rep(j, 10) cin >> C[i][j];
	rep(i, H) rep(j, W) cin >> A[i][j];	

	//rep(i, 10) dist[i][i] = 0;

	rep(k, 10) rep(i, 10) rep(j, 10) {
		C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
	}

	ll maryoku = 0;

	rep(i, H) rep(j, W) {
		if (A[i][j] != -1) maryoku += C[A[i][j]][1];
	}

	cout << maryoku << endl;

	return 0;
}
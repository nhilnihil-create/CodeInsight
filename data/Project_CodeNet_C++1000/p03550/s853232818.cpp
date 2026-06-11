#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////



int main() {

	ll N, Z, W;
	cin >> N >> Z >> W;

	vector<ll> a(N + 1);

	repn(i, N) cin >> a[i];

	a[0] = W;

	vector<ll> dpX(N), dpY(N);

	dpX[N - 1] = abs(a[N - 1] - a[N]);
	dpY[N - 1] = dpX[N - 1];

	for (int i = N - 2; i >= 0; i--) {
		dpX[i] = abs(a[N] - a[i]);
		for (int j = i+1; j <= N - 1; j++) {
			dpX[i] = max(dpX[i], dpY[j]);
		}

		dpY[i] = abs(a[N] - a[i]);
		for (int j = i + 1; j <= N - 1; j++) {
			dpY[i] = min(dpY[i], dpX[j]);
		}
	}

	cout << dpX[0];

	system("PAUSE");

	

}

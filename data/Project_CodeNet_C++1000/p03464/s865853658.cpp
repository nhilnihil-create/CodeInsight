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

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

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
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////

ll K;
vector<ll> A;

ll win(ll N) {
	repn(i, K) { N = N / A[i] * A[i]; }
	return N;
}


int main() {
	cin >> K;

	A.assign(K + 1, 0);
	repn(i, K) cin >> A[i];

	ll l = 0;
	ll r = INF;

	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (win(m) > 2) { r = m; }
		else { l = m; }
	}

	ll X = r;

	l = 0;
	r = INF;

	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (win(m) >= 2) { r = m; }
		else { l = m; }
	}

	ll Y = r;

	if (X == Y) { cout << -1; }
	else { cout << Y << " " << X - 1; }
	

	system("PAUSE");
}

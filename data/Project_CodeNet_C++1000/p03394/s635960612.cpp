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


int main() {
	ll N;
	cin >> N;

	if (N == 3) {
		cout << 2 << " " << 5 << " " << 63;
	}
	if (N >= 4) {
		ll M = min(N / 2, 7500);

		ll t = min(M / 2,2500);
		ll s = M - t;
		ll u = N - 2 * M;

		rep(i, s) {
			cout << 6 * i + 2 << " " << 6 * i + 4 << " ";
		}

		rep(i, t) {
			cout << 12 * i + 3 << " " << 12 * i + 9<<" ";
		}

		repn(i, u) { cout << 6 * i<<" "; }
	}

	system("PAUSE");
}

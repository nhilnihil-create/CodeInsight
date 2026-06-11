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
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
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
	string S;
	cin >> S;

	vector<ll> D(N + 1,0), M(N + 1,0), C(N + 1,0);

	repn(i, N) {
		D[i] = D[i - 1];
		if (S[i - 1] == 'D') { D[i]++; }

		M[i] = M[i - 1];
		if (S[i - 1] == 'M') { M[i]++; }

		C[i] = C[i - 1];
		if (S[i - 1] == 'C') { C[i]++; }
	}

	ll Q;
	cin >> Q;

	rep(x, Q) {
		ll K;
		cin >> K;

		ll ans = 0;

		rep(i, N) {
			if (S[i] == 'C') {
				ans += M[i] * (D[i] - D[max(0, i - K + 1)]);
			}

			if (S[i] == 'D') {
				ans -= M[i] * (C[min(N, i + K)] - C[i + 1]);
			}
		}

		cout << ans<<endl;
	}
	system("PAUSE");
}

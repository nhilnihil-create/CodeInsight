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
const ll MOD = 998244353;
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
	vector<vector<ll>> b(N + 1, vector<ll>(N + 1, 0));

	vector<ll> ans(N + 1);

	repn(i, N) {
		cin >> b[0][i];
	}

	rep(i,N) {
		ll M = N - i;
		for (ll j = M; j >= 1; j--) {
			if (b[i][j] > j) { b[N][0] = -1; break; }
			if (b[i][j] == j) { ans[M] = j; break; }
			if (j == 1) { b[N][0] == -1; break; }
		}

		if (b[N][0] == -1) { break; }

		repn(j, M) {
			if (j < ans[M]) { b[i + 1][j] = b[i][j]; }
			if (j > ans[M]) { b[i + 1][j - 1] = b[i][j]; }
		}
	}

	if (b[N][0] == -1) { cout << -1; }
	else {
		repn(i, N) {
			cout << ans[i] << endl;
		}
	}
	
	
	system("PAUSE");
}

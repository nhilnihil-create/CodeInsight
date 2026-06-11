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
	ll N, K;
	cin >> N >> K;

	vector<ll> a(N + 1);
	repn(i, N) cin >> a[i];

	vector<ll> s(N + 1, 0);
	repn(i, N) s[i] = s[i - 1] + a[i];

	vector<ll> b[51];
	rep(i, N) {
		for (ll j = i + 1; j <= N; j++) {
			b[0].push_back(s[j] - s[i]);
		}
	}

	ll M = b[0].size();
	vector<ll> c(M);

	ll ans = 0;

	rep(k, 50) {
		ll one = 0;
		rep(j, b[k].size()) {
			c[j] = (b[k][j] >> (49-k)) % 2;
			if (c[j] == 1) { one++; }
		}

		
		if (one >= K) {
			ans += 1ull << (49 - k);
			rep(j, b[k].size()) {
				if (c[j] == 1) { b[k + 1].push_back(b[k][j]); }
			}
		}

		else {
			rep(j, b[k].size()) {
				b[k + 1].push_back(b[k][j]);
			}
		}

	}


	cout << ans;
	system("PAUSE");
}

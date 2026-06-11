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
	ll N, A, B;
	cin >> N >> A >> B;

	vector<ll> p(N + 1,0);
	repn(i, N) cin >> p[i];

	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, INF));

	dp[0][0] = 0;
	
	repn(i, N) {
		dp[i][0] = dp[i - 1][0] + A;

		repn(j, i - 1) {
			if (p[i] > p[j]) { dp[i][j] = dp[i - 1][j] + A; }
			else { dp[i][j] = dp[i - 1][j] + B; }
		}

		rep(j, i) {
			if (p[i] > p[j]) { dp[i][i] = min(dp[i - 1][j], dp[i][i]); }
		}
	}

	ll ans = INF;
	rep(i, N + 1) {
		ans = min(ans, dp[N][i]);
	}

	cout << ans;
	
	
	system("PAUSE");
}

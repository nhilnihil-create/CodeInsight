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
	vector<ll> C(N + 1);
	repn(i, N) cin >> C[i];

	vector<ll> pre(300000, -1), dp(N + 1, 0);

	dp[0] = 1;

	repn(i, N) {
		dp[i] = dp[i - 1];

		if (pre[C[i]] != -1 && pre[C[i]]!=i-1) { dp[i] += dp[pre[C[i]]]; }

		pre[C[i]] = i;

		dp[i] %= MOD;

		//cout << dp[i] << endl;
	}

	cout << dp[N];

	system("PAUSE");

}




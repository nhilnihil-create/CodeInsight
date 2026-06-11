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

	vector<ll> A(N + 1), B(N + 1), sa(N + 1);

	repn(i, N) cin >> A[i];
	repn(i, N) cin >> B[i];
	repn(i, N) sa[i] = B[i] - A[i];

	sort(++sa.begin(), sa.end(),greater<ll>());

	ll ans = 0;
	ll sum = 0;

	for(ll i=1; sa[i]>0&&i<=N; i++) {
		ans++;
		sum += sa[i];
		//cout << sum << endl;
	}

	for (ll i = N; sum > 0 && i >= 1; i--) {
		sum += sa[i];
		ans++;
	}

	if (sum > 0) { ans = -1; }

	cout << ans;

	system("PAUSE");
}

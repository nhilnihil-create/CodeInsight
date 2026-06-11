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

	vector<ll> a(N + 2);
	repn(i, N) cin >> a[i];
	a[N + 1] = 0;

	vector<ll> b;

	ll c = 1;
	repn(i, N) {
		if (a[i + 1] != a[i]) { b.push_back(c); c = 1; }
		else { c++; }
	}

	ll ans = 0;
	for (ll c : b) {
		ans += c / 2;
	}
	cout << ans;
	system("PAUSE");

}




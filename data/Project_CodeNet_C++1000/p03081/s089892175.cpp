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
const ll MOD =998244353;
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

ll N, Q;
vector<char> s;

vector<char> t, d;

ll ch(ll pos) {
	repn(i, Q) {
		if (s[pos] == t[i]) {
			if (d[i] == 'L') { pos--; }
			else { pos++; }
		}
	}

	if (pos == 0) { return 0; }
	if (pos == N + 1) { return 2; }
	return 1;
}



int main() {
	cin >> N >> Q;
	s.resize(N + 2);
	t.resize(Q + 1);
	d.resize(Q + 1);

	s[0] = '?';
	s[N + 1] = '?';
	repn(i, N) cin >> s[i];

	repn(i, Q) { cin >> t[i] >> d[i]; }

	ll l = 0;
	ll r = N + 1;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (ch(m) >= 1) { r = m; }
		else { l = m; }
	}

	ll left = l;

	l = 0;
	r = N + 1;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (ch(m) ==2) { r = m; }
		else { l = m; }
	}

	ll right=r;
	
	cout << right - left - 1;
	system("PAUSE");
}

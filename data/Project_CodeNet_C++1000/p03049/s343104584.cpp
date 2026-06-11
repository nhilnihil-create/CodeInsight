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

	vector<string> s(N + 1);
	repn(i, N) cin >> s[i];

	ll a = 0;
	ll b = 0;
	ll c = 0;

	ll ans = 0;
	repn(i, N) {
		ll M = s[i].size();
		rep(j, M - 1) { if (s[i][j] == 'A'&&s[i][j+1] == 'B') { ans++; } }

		if (s[i][0] == 'B'&&s[i][M - 1] == 'A') { a++; }
		else if (s[i][0] == 'B') { b++; }
		else if (s[i][M - 1] == 'A') { c++; }
	}

	if (b == 0 && c == 0 && a!=0) { ans += a - 1; }
	else { ans += a + min(b, c); }

	cout << ans;


	system("PAUSE");
}

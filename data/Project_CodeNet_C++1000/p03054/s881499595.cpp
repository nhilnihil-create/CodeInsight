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

ll H, W, N, sr, sc;


bool ch(vector<ll> a, vector<ll> b , ll L, ll s) {

	
	vector<ll> c(2 * N + 1);

	repn(i, N) {
		c[2 * i - 1] = b[N + 1 - i];
		c[2 * i] = a[N + 1 - i];
	}

	ll le = 1;
	ll ri = L;

	for (ll i = 2; i <= 2 * N; i++) {
		if (i % 2 == 0) {
			if (c[i] == 1) { ri--; }
			if (c[i] == -1) { le++; }
		}

		if (i % 2 == 1) {
			if (c[i] == 1) { le = max(le - 1, 1); }
			if (c[i] == -1) { ri = min(ri + 1, L); }
		}


		if (le > ri) { return false; }
	}

	if (s<le || s>ri) { return false; }
	return true;

}

int main() {

	cin >> H >> W >> N >> sr >> sc;
	string S, T;
	cin >> S >> T;

	vector<ll> a(N + 1, 0), b(N + 1, 0), c(N + 1, 0), d(N + 1, 0);
	repn(i, N) {
		if (S[i - 1] == 'D') { a[i] = 1; }
		if (S[i - 1] == 'U') { a[i] = -1; }
		if (S[i - 1] == 'R') { c[i] = 1; }
		if (S[i - 1] == 'L') { c[i] = -1; }
		if (T[i - 1] == 'D') { b[i] = 1; }
		if (T[i - 1] == 'U') { b[i] = -1; }
		if (T[i - 1] == 'R') { d[i] = 1; }
		if (T[i - 1] == 'L') { d[i] = -1; }
	}

	if (ch(a, b, H, sr) && ch(c, d, W, sc)) { cout << "YES"; }
	else { cout << "NO"; }

	
	
	system("PAUSE");
}

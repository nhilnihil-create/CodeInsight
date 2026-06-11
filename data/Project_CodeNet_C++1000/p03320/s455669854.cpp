#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 4e18;

ll p;
ll f(ll d) {
	ll x = d + p, y = d + p * 10;
	string xx = to_string(x), yy = to_string(y);
	int xsum = 0, ysum = 0;
	rep(i, 0,xx.size()) {
		xsum += xx[i] - '0';
	}
	rep(i, 0, yy.size()) {
		ysum += yy[i] - '0';
	}
	if (x * ysum <= y * xsum) return x;
	else {
		p *= 10;
		return y;
	}
}

int main() {
	ll k; cin >> k;
	ll n = 1; p = 1;
	rep(i, 0, k) {
		cout << n << endl;
		n = f(n);
	}
	return 0;
}
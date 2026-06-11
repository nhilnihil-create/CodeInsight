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

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

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
	return a * b / gcd(a, b);
}





///////////////////////////


int main() {
	ll H, W, D;
	cin >> H >> W >> D;

	vector<ll> h(H*W + 1), w(H*W + 1);

	repn(i, H) {
		repn(j, W) {
			ll A;
			cin >> A;
			h[A] = i;
			w[A] = j;
		}
	}

	vector<ll> pow(H*W + 1);

	repn(i, H*W) {
		if (i <= D) { pow[i] = 0; }
		else {
			pow[i] = pow[i - D] + abs(h[i] - h[i - D]) + abs(w[i] - w[i - D]);
		}
	}

	ll Q;
	cin >> Q;
	repn(i, Q) {
		ll L, R;
		cin >> L >> R;
		cout << pow[R] - pow[L] << endl;
	}

	system("PAUSE");

}

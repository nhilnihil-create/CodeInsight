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

	ll N;
	cin >> N;
	bool r[200];
	ll y[200];

	repn(i, N) {
		ll a, b;
		cin >> a>> b;
		y[a] = b;
		r[a] = 1;
	}

	repn(i, N) {
		ll c, d;
		cin >> c >> d;
		y[c] = d;
		r[c] = 0;
	}

	ll ans = 0;
	rep(i, 2 * N) {
		if (r[i] == 0) {
			ll v = -1;
			ll ind = -1;

			rep(j, i) {
				if (r[j] == 1 && y[j] > v&&y[j] < y[i]) {
					v = y[j];
					ind = j;
				}
			}

			if (ind != -1) {
				ans++;
				y[ind] = INF;

				//cout << i << ind << endl;
			}

		}
	}

	cout << ans;
	system("PAUSE");

}

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

string S;

string ans() {
	ll N = S.size();
	ll b[26] = {};

	rep(i, N) {
		b[S[i] - 'a'] = 1;
	}

	rep(i, 26) {
		if (b[i] == 0) {
			char c = 'a' + i;
			return S + c;
		}
	}

	for (ll i = N - 1; i >= 0; i--) {
		ll X = S[i]-'a';
		for (ll j = X + 1; j < 26; j++) {
			if (b[j] == 0) {
				char c = 'a' + j;
				S = S.substr(0, i);
				return S + c;
			}
		}

		b[X] = 0;

	}

	return "-1";
}


int main() {
	cin >> S;
	cout << ans();
	
	
	system("PAUSE");

}




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
	
	string S;
	cin >> S;

	ll N = S.size();

	char str[7] = { 'k','e','y','e','n','c','e' };

	ll a = 0;
	rep(i, 7) {
		if (S[i] == str[i]) { a++; }
		else { break; }
	}

	ll b = 0;
	rep(i, 7) {
		if (S[N - 1 - i] == str[6 - i]) { b++; }
		else { break; }
	}

	if (a + b >= 7) { cout << "YES"; }
	else { cout << "NO"; }

	system("PAUSE");
}

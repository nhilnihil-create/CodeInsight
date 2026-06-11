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
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

///////////////////////////



int main() {

	string s;
	cin >> s;

	ll a[MAX] = {};
	ll ab[MAX] = {};
	ll abc[MAX] = {};

	ll q = 1;

	repn(i, s.size()) {
		if (s[i - 1] == 'A') {
			a[i] = a[i - 1] + q;
			ab[i] = ab[i - 1];
			abc[i] = abc[i - 1];
		}

		if (s[i - 1] == 'B') {
			a[i] = a[i - 1];
			ab[i] = ab[i - 1] + a[i - 1];
			abc[i] = abc[i - 1];
		}

		if (s[i - 1] == 'C') {
			a[i] = a[i - 1];
			ab[i] = ab[i - 1];
			abc[i] = abc[i - 1] + ab[i - 1];
		}

		if (s[i - 1] == '?') {
			a[i] = 3*a[i - 1] + q;
			ab[i] = 3*ab[i - 1] + a[i - 1];
			abc[i] = 3*abc[i - 1] + ab[i - 1];
			q=q*3%MOD;
		}
		a[i] %= MOD;
		ab[i] %= MOD;
		abc[i] %= MOD;
		
	}

	cout << abc[s.size()];

	
	system("PAUSE");
}
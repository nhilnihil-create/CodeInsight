#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

ll gcd(ll a, ll b) {
	if (a > b) {
		swap(a, b);
	}
	if (a == 0) {
		return b;

	}

	return gcd(b % a, a);
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a < b) {
			cout << "No" << endl;
			continue;
		}
		if (b > d) {
			cout << "No" << endl;
			continue;
		}

		if (b <= c) {
			cout << "Yes" << endl;
			continue;
		}

		ll g = gcd(b, d);
		if (c >= (b - g + a % g)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
			
	}
}
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

int main() {
	ll n;
	cin >> n;

	ll sum = 0;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i != 0) {
			continue;
		}

		ll m = n / i - 1;
		if (m <= i) {
			continue;
		}

		sum += m;


	}
	cout << sum << endl;
}
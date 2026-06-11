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
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n;
	cin >> n;

	vector<ll> a(n);
	vector<ll> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}


	vector<ll> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
	}

	sort(c.begin(), c.end());

	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > 0) {
			break;
		}
		ll tmp = abs(c[i]) / 2;
		cnt += tmp;
		c[i] += tmp * 2;
		if (c[i] < 0) {
			c[i] += 2;
			cnt++;
		}
	}

	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++) {
		cnt -= c[i];
	}
	//cout << cnt << endl;
	if (cnt >= 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}
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
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;


int main() {
	int n;
	cin >> n;

	vector<ll> h(n);
	ll sa = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		h[i] = a + b;
		sa += a;
	}

	ll ans = sa;
	sort(h.begin(), h.end(), greater<ll>());
	for (int i = 1; i < n; i += 2) {
		ans -= h[i];
	}

	cout << ans << endl;
}
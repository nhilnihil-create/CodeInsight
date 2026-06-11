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
	int n, t, a;
	cin >> n >> t >> a;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	t *= 1000;
	a *= 1000;
	int id = 0;
	for (int i = 0; i < n; i++) {
		if (abs(t - 6 * h[i] - a) < abs(t - 6 * h[id] - a)) {
			id = i;
		}
	}

	cout << id + 1 << endl;
}

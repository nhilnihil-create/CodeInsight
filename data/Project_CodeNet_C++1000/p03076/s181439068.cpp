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
	vector<pii> m(5);
	for (int i = 0; i < 5; i++) {
		int t;
		cin >> t;
		int w = (10 - t % 10) % 10;

		m[i] = make_pair(w, t);

	}

	sort(m.begin(), m.end());

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += m[i].first + m[i].second;
	}

	sum -= m[4].first;

	cout << sum << endl;
}

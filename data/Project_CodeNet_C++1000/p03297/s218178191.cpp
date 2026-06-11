#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int T; cin >> T;
	while (T--) {
		[]() {
			ll a, b, c, d;
			cin >> a >> b >> c >> d;
			if (a < b || d < b) {
				cout << "No" << endl;
				return;
			}
			if (c >= b && d >= b) {
				cout << "Yes" << endl;
				return;
			}
			ll g = gcd(b, d);
			if (b - g + a%g > c) cout << "No" << endl;
			else cout << "Yes" << endl;
		}();
	}
	return 0;
}
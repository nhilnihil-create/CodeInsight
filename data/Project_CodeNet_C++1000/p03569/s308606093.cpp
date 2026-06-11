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



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (a > b) {
		swap(a, b);
	}

	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

ll pow(int k) {
	ll p = 2;
	ll a = 1;

	for (int i = 0; i < 32; i++) {
		if (((k >> i) & 1) == 1) {
			a = (a * p) % MOD;
		}
		p = (p * p) % MOD;
	}
	return a;
}

int main() {
	string s;
	cin >> s;
	
	int r = 0;
	int l = s.length() - 1;

	int cnt = 0;
	while (r < l) {
		if (s[r] == s[l]) {
			r++;
			l--;
			continue;
		}

		if (s[r] == 'x') {
			cnt++;
			r++;
			continue;
		}

		if (s[l] == 'x') {
			cnt++;
			l--;
			continue;
		}

		cout << -1 << endl;
		return 0;
	}

	cout << cnt << endl;
	
	
}

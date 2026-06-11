#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	ll T;
	cin >> T;
	vector<ll> A(T), B(T), C(T), D(T);
	for (int i = 0; i < T; ++i) cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < T; ++i) {
		ll a = A[i], b = B[i], c = C[i], d = D[i];

		if (b > a) cout << "No" << endl;
		else if (b > d) cout << "No" << endl;
		else if (b <= c) cout << "Yes" << endl;
		else {
			ll g = gcd(b, d);
			if (c < b - g + (a % g)) cout << "No" << endl;
			else cout << "Yes" << endl;
		}

	}
}
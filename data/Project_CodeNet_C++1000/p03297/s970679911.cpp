#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

template<typename T>
T gcd(T a, T b) {
	if (a%b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	int T;
	cin >> T;
	vector<ll> A(T);
	vector<ll> B(T);
	vector<ll> C(T);
	vector<ll> D(T);
	for (int i = 0; i < T; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < T; ++i) {
		if ((A[i] < B[i]) || (B[i] > D[i])) {
			cout << "No" << endl;
			continue;
		}
		if (B[i] <= C[i]) {
			cout << "Yes" << endl;
			continue;
		}

		ll g = gcd(B[i], D[i]);
		ll x = B[i] - g + (A[i] % g);
		if (x > C[i]) { cout << "No" << endl; }
		else { cout << "Yes" << endl; }
	}

	return 0;
}

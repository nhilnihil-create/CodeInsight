#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N; cin >> N;
	long long x = 0, y = 0, T = 0;
	for (long long i = 0; i < N; i++) {
		long long t, X, Y;
		cin >> t >> X >> Y;
		if ((abs(X - x) + abs(Y - y) - (t - T)) > 0 || (abs(X - x) + abs(Y - y) - (t - T)) % 2 != 0) {
			cout << "No" << endl;
			return 0;
		}
		x = X;
		y = Y;
		T = t;
	}
	cout << "Yes" << endl;
}

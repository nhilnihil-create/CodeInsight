#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;


int main() {

	ll N;

	cin >> N;

	vector<ll> oX(N), X(N);

	rep(i, N) {
		cin >> oX[i];
		X[i] = oX[i];
	}

	sort(X.begin(), X.end());

	ll c, M, L, H;

	c = (N + 1) / 2;


	if (N == 2) {
		cout << oX[1] << endl;
		cout << oX[0] << endl;
	}
	else {
		M = X[c - 1];
		L = X[c - 2];
		H = X[c];

		rep(i, N) {

			if (N % 2 == 0) {
				if (M >= oX[i]) {
					cout << H << endl;
				}
				else {
					cout << M << endl;
				}
			}
			else {
				if (M <= oX[i]) {
					cout << L << endl;
				}
				else {
					cout << M << endl;
				}
			}
		}
	}
	return 0;
}

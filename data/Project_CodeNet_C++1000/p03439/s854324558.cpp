#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)


int main() {
	li n;
	cin >> n;

	cout << 0 << endl;

	string state0;
	cin >> state0;
	if (state0 == "Vacant") {
		return 0;
	}
	cout << n - 1 << endl;
	string state1;
	cin >> state1;
	if (state1 == "Vacant") {
		return 0;
	}

	li left = 0;
	li right = n - 1;
	rep(i, 19) {
		li med = (left + right) / 2;
		cout << med << endl;
		string state;
		cin >> state;
		if (state == "Vacant") {
			return 0;
		}
		if ((med - left) % 2 == 0) {
			if (state == state0) {
				left = med;
				state0 = state;
			} else {
				right = med;
			}
		} else {
			if (state == state0) {
				right = med;
			} else {
				left = med;
				state0 = state;
			}
		}
	}
	throw;


	return 0;
}

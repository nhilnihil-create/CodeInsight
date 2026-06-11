#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)

li a[10100];
li b[10100];
li n;

inline bool check() {
	cin >> n;
	li sa = 0;
	rep(i, n) {
		cin >> a[i];
		sa += a[i];
	}
	li sb = 0;
	rep(i, n) {
		cin >> b[i];
		sb += b[i];
	}
	if (sa > sb) {
		return false;
	}
	li num = sb - sa;

	li num1 = num;
	rep(i, n) {
		if (a[i] < b[i]) {
			li cnt = (b[i] - a[i] + 1) / 2;
			a[i] += cnt * 2;
			num1 -= cnt;
		}
	}
	if (num1 < 0) {
		return false;
	}
	return true;
}

int main() {
	cout << (check() ? "Yes" : "No") << endl;

	return 0;
}

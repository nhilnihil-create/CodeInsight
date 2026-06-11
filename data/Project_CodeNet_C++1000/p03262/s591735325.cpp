#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	int n, x,tmp,tmp2,d=-1;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (i == 0) {
			tmp2 = tmp - x;
			continue;
		}
		d = gcd(abs(tmp - x), abs(tmp2));
		tmp2 = d;
	}
	if (d == -1) {
		cout << abs(tmp - x) << endl;
	}
	else {
		cout << d << endl;
	}
}
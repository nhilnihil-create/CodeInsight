#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long answer = 0;
	if (b >= c) {
		cout << b + c;
	} else {
		if (b + a >= c) {
			cout << b + c;
		} else {
			c -= b + a;
			cout << b + b + a + (c > 0);
		}
	}
}
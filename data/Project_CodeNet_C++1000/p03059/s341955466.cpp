#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b, t;
	cin >> a >> b >> t;
	int now = 0, bis = -b;
	while (now <= t) {
		bis += b;
		now += a;
	}
	cout << bis << endl;
}
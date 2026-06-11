#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main() {
	cin >> x >> y;
	if (x % y == 0)
		return cout << -1, 0;
	cout << x;
	return 0;
}

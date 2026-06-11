#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	if (x % y == 0) {
		cout << -1;
		return 0;
	}
	if ((x * 2) % y != 0)
		cout << x * 2;
	else 
		cout << x * 3;
	
	return 0;
}
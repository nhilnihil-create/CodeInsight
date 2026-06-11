#include <bits/stdc++.h>
using namespace std;

signed main () {
	int a, b;
	cin >> a >> b;
	if ((a & 1) && (b & 1))
		cout << "Odd\n";
	else
		cout << "Even\n";
}

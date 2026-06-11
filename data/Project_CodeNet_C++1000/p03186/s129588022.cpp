#include<bits/stdc++.h>
using namespace std;

signed main() {
	long long a, b, c;
	cin >> a >> b >> c;

	long long ans = 0;
	if (c >= a + b + 2)  cout << a + b + 1 + b << endl;
	else cout << b + c << endl;

	return 0;
}

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int a, b;
	cin >> a >> b;
	char ans;
	if (a + b == 15) ans = '+';
	else if (a * b == 15) ans = '*';
	else ans = 'x';
	cout << ans << endl;
	return 0;	
}
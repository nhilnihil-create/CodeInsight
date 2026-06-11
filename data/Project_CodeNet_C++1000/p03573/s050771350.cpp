#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b, c; cin >> a >> b >> c;
	int ans;
	if (a == b) ans = c;
	if (b == c) ans = a;
	if (c == a) ans = b;
	cout << ans << endl;
	return 0;
}
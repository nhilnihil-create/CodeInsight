#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	int ans;
	if (a == b) ans = 2 * a;
	else {
		if (a < b) swap(a, b);
		ans = a + (a - 1);
	}	
	cout << ans << endl;
	return 0;
}
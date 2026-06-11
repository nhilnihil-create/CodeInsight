#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	string ans;
	if (a + b == 15) {
		ans = "+";
	}
	else if (a * b == 15) {
		ans = "*";
	}
	else {
		ans = "x";
	}
	cout << ans << endl;
    return 0;
}
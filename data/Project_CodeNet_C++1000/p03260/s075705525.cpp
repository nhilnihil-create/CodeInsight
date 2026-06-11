#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	string ans = "No";
	for (int i = 1; i <= 3; i++) {
		if (a * b * i % 2 == 1) ans = "Yes";
	}
	cout << ans << endl;
	return 0;
}
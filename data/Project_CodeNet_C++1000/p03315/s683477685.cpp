#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = 0;
	for (auto c : s) {
		if (c == '+') { ++ans; }
		else { --ans; }
	}
	cout << ans << endl;

	return 0;
}

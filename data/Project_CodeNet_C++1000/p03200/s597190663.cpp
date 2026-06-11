#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	cin >> s;

	Int ans = 0;
	Int W = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'W') {
			++W;
		} else {
			ans += W;
		}
	}
	cout << ans << "\n";

	return 0;
}

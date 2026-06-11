#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < (1 << 3); i++) {
		int ans = s[0] - '0';
		string t = "";
		t += s[0];
		for (int j = 0; j < 3; j++) {
			if (i & (1 << j)) {
				ans += s[j + 1] - '0';
				t += '+';
			} else {
				ans -= s[j + 1] - '0';
				t += '-';
			}
			t += s[j + 1];
		}
		if (ans == 7) {
			cout << t + "=7\n" << endl;
			return 0;
		}
	}
}
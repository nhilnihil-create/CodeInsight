#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	int bcount = 0;
	long long res = 0;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'W') {
			res += bcount;
		}
		else {
			bcount++;

		}
	}
	cout << res << endl;

	return 0;
}
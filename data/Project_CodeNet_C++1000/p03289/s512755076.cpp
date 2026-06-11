#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool ok = s[0] == 'A';

	int idx_c = -1;
	for (int i = 2; i <= s.size() - 2; i++) {
		if (s[i] == 'C') {
			idx_c = i;
			break;
		}
	}
	if (idx_c < 0) {
		ok = false;
	}

	for (int i = 1; i < s.size(); i++) {
		if (i == idx_c) {
			continue;
		}

		if (isupper(s[i])) {
			ok = false;
			break;
		}
	}

	cout << (ok ? "AC": "WA") << endl;
	return 0;
}

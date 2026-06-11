#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int cnt = 0, c = 0;
	for (int i = 0; i < S.size(); i++) {
		if (!i) {
			if (S.at(i) != 'A') {
				cout << "WA" << endl;
				return 0;
			}
		}
		else if ((i >= 2) && (i <= S.size() - 2)) {
			if (S.at(i) == 'C') c++;
		}

		if ((S.at(i) >= 'A') && (S.at(i) <= 'Z')) {
			cnt++;
		}
	}

	if ((cnt != 2) || (c != 1)) {
		cout << "WA" << endl;
	}
	else {
		cout << "AC" << endl;
	}
}
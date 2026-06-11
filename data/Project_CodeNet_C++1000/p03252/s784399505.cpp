#include "bits/stdc++.h"
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	bool ok = true;
	map<char, char> ma, ima;
	for (int n = 0;n<S.size();++n) {
		char s = S[n];
		char t = T[n];
		if (ma.count(s)) {
			if (t != ma[s]) {
				ok = false;
			}
		}
		if (ima.count(t)) {
			if (s != ima[t]) {
				ok = false;
			}
		}
		ma[s] = t;
		ima[t] = s;
	}

	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
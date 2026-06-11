#include "bits/stdc++.h"

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	for (int i = S.size() - T.size(); i >= 0; --i) {
		bool b = true;
		for (int j = 0; j < T.size(); ++j) {
			if (S[i + j] != '?') {
				if (S[i + j] != T[j]) {
					b = false;
				}
			}
		}
		if (b) {
			for (int j = 0; j < S.size(); ++j) {
				if ((j < i) || ((i + T.size()) <= j)) {
					if (S[j] == '?') {
						S[j] = 'a';
					}
				}
				else {
					S[j] = T[j - i];
				}
			}
			cout << S << endl;
			return 0;
		}
	}
	cout << "UNRESTORABLE" << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	string Sd, T, S = "UNRESTORABLE";
	cin >> Sd >> T;
	for (int i = Sd.size() - T.size(); i >= 0; i--) {
		for (int j = 0; j < T.size(); j++) {
			if (T[j] == Sd[i + j] || Sd[i + j] == '?') {
				if (j != T.size() - 1)
					continue;
			} else {
				break;
			}
			S = Sd;
			for (int k = 0; k < T.size(); k++) {
				S[i + k] = T[k];
			}
			for (int k = 0; k < S.size(); k++) {
				if (S[k] == '?') {
					S[k] = 'a';
				}
			}
			cout << S << endl;
			return 0;
		}
	}
	cout << S << endl;
	return 0;
}
